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
using P = pair<ll,ll>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    map<ll, P> mp;
    rep(i, N){
        int t, x, a;
        cin >> t >> x >> a;
        mp[t] = P(x, a);
    }

    vector<vector<ll>> dp(5, vector<ll>(100010, 0));
    for(int i=1;i<5;i++) dp[i][0]=-1e18;

    for(int t=1; t<=100000; t++){
        for(int i=0; i<=4; i++){
			dp[i][t]=dp[i][t-1];
			if(i!=0)dp[i][t]=max(dp[i][t],dp[i-1][t-1]);
			if(i!=4)dp[i][t]=max(dp[i][t],dp[i+1][t-1]);
        }
        if(mp.find(t) == mp.end()) continue;
        dp[mp[t].first][t] += mp[t].second;
    }

    ll ans = 0;
    rep(i, 5){
        ans = max(dp[i][100000], ans);
    }
    cout << ans << endl;

    return 0;
} 