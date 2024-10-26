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
    string S;
    cin >> S;

    vector<vector<int>> dp(N+1, vector<int>(3, 0));

    rep(i, N){
        if(S[i] == 'R'){
            dp[i+1][1] = max(dp[i][0] + 1,  dp[i][2] + 1);
            dp[i+1][0] = max(dp[i][1],  dp[i][2]);
        }
        if(S[i] == 'P'){
            dp[i+1][2] = max(dp[i][0] + 1,  dp[i][1] + 1);
            dp[i+1][1] = max(dp[i][0],  dp[i][2]);
        }
        if(S[i] == 'S'){
            dp[i+1][0] = max(dp[i][1] + 1,  dp[i][2] + 1);
            dp[i+1][2] = max(dp[i][0],  dp[i][1]);
        }
    }

    int ans = 0;
    rep(i, 3) ans = max(ans, dp[N][i]);
    cout << ans << endl;

    return 0;
} 