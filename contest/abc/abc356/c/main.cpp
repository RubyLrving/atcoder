#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9
 
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> C(M);
    vector<char> R(M);
    vector<vector<int>> A(M, vector<int>(N, 0));

    rep(i, M){
        cin >> C[i];
        rep(j, C[i]) cin >> A[i][j];
        cin >> R[i];
    }


    int ans = 0;
    for(int tmp=0; tmp < (1 << N); tmp++){
        bitset<16> s(tmp);

        int ok = 1;
        rep(i, M){
            int cnt = 0;
            rep(j, C[i]){
                if(s.test(A[i][j]-1) == 1){
                    cnt++;
                }
            }
            if(cnt<K && R[i] == 'o') ok=0;
            if(cnt>=K && R[i] == 'x') ok=0;
        }
        if(ok){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
} 