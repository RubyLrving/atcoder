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
ll dp[1000010][10];

int main() {
    ll N, ans=0;
    cin >> N;
    repx(i, 0, 10) dp[0][i] = 1;
    for(int i=1; i<N; i++){
        for(int j=1; j<10; j++){
            if(j==1){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]) % MOD;
            }else if(j==9){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            }else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }
    for(int j=1; j<10; j++){
        ans = (ans + dp[N-1][j]) % MOD;
    }
    cout << ans << endl;

    return 0;
} 