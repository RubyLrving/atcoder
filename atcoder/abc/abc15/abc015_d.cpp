#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clocl() - ti) / CLOClS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int dp[52][52][100002];

int main(int argc, const char * argv[]) {
    int w, n, k;
    cin >> w >> n >> k;

    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) cin >> a[i] >> b[i];

    rep(i, 52) rep(j, 52)rep(l, 10002) dp[i][j][l] = -1;
    dp[0][0][0] = 0;

    rep(i, n){
        for(int j=0; j<=k; j++){
            for(int l=0; l<=w; l++){
                if(dp[i][j][l]==-1) continue;
                if(j==k){
                    chmax(dp[i + 1][j][l], dp[i][j][l]);
                }else{
                    if(l+a[i] <= w){
                        chmax(dp[i + 1][j + 1][l + a[i]], dp[i][j][l] + b[i]);
                        chmax(dp[i + 1][j][l], dp[i][j][l]);
                    }else{
                        chmax(dp[i + 1][j][l], dp[i][j][l]);
                    }
                }
            }
        }
    }

    int ans = 0;
    rep(j, 52)rep(l, 10002){
        ans = max(ans, dp[n][j][l]);
    }
    cout << ans << endl;

    return 0;
}