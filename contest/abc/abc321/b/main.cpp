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
    int N, X;
    cin >> N >> X;
    vector<int> A(N-1);
    rep(i, N-1) cin >> A[i];

    for(int i=0; i<=100; i++){
        vector<int> T(N);
        rep(j, N-1) T[j] = A[j];
        T[N-1] = i;
        sort(T.begin(), T.end());

        int total = 0; 
        repx(j, 1, N-1) total += T[j];
        if(total>=X){
            cout << i << endl;
            return 0;
        } 
    }
    cout << -1 << endl;

    return 0;
} 