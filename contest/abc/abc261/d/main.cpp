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
    int N, M;
    cin >> N >> M;
    vector<ll> X(N+1);
    repx(i, 1, N+1) cin >> X[i];
    vector<ll> Bonus(N+1, 0);
    rep(i, M){
        ll C, Y;
        cin >> C >> Y;
        Bonus[C] = Y;
    }

    vector<vector<ll>> dp(N+1, vector<ll>(N+1, -1));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++) dp[i][j] = dp[i-1][j-1] + X[i] + Bonus[j];

        dp[i][0] = 0;

        for(int j = 0; j < i; j++) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
    }

    ll ans = 0;
	for (int i = 0; i <= N; i++) ans = max(ans, dp[N][i]);
	cout << ans << endl;

    return 0;
} 