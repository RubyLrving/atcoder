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

ll MOD = 998244353;

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<vector<ll>> dp(N+1, vector<ll>(K+1, 0));
    dp[0][0] = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            for(int k=1; k<=M; k++){
                if(j+k<=K) dp[i+1][j+k] = (dp[i+1][j+k] + dp[i][j]) % MOD;
            }
        }
    }
    ll res = 0;
    for(int i=1; i<=K; i++){
        res = (res + dp[N][i]) % MOD;
    }
    cout << res << endl;

    return 0;
} 