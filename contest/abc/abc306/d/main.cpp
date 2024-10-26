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
    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    vector<vector<ll>> dp(N+1, vector<ll>(2, 0));

    rep(i, N){
        if(X[i] == 0){
            dp[i+1][1] = dp[i][1];
            dp[i+1][0] = max(max(dp[i][0], dp[i][1] + Y[i]), dp[i][0] + Y[i]);
        }else{
            dp[i+1][1] = max(dp[i][1], dp[i][0] + Y[i]);
            dp[i+1][0] = dp[i][0];
        }
    }

    ll ans = max(dp[N][1], dp[N][0]);
    cout << ans << endl;

    return 0;
} 