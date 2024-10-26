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
    int N, K, max_num=0;
    cin >> N >> K;
    vector<int> A(N), B(K);
    for(auto &a:A){
        cin >> a;
        max_num = max(max_num, a);
    }
    for(auto &b:B) cin >> b;

    int ans=0;
    for(int i=0; i<N; i++){
        if(max_num != A[i]) continue;
        for(int j=0; j<K; j++){
            if(i == B[j]-1) ans=1;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 