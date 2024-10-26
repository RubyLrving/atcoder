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
    int N, S;
    cin >> N >> S;
    vector<vector<string>> dp(N+1, vector<string>(S+1, "B"));
    dp[0][0] = "";
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        for(int j=0; j<=S; j++){
            if(dp[i][j] == "B") continue;
            if(j+a<=S && dp[i+1][j+a] == "B") dp[i+1][j+a] = dp[i][j] + "H";
            if(j+b<=S && dp[i+1][j+b] == "B") dp[i+1][j+b] = dp[i][j] + "T";
        }
    }
    if(dp[N][S].size() == N) cout << "Yes" << endl << dp[N][S].substr(0, N) << endl;
    else cout << "No" << endl;

    return 0;
} 