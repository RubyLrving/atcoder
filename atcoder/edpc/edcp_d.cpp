#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

ll dp[110][100010];

int main(int argc, const char * argv[]) {
    int n, w;
    cin >> n >> w;

    vector<int> w_list(n);
    vector<int> v_list(n);

    rep(i, n) cin >> w_list[i] >> v_list[i];

    for(int i=0; i<n; i++){
        for(int sum_w=0; sum_w <= w; sum_w++){
            if(sum_w - w_list[i] >= 0){
                chmax(dp[i+1][sum_w], dp[i][sum_w - w_list[i]] + v_list[i]);
            }
            chmax(dp[i+1][sum_w], dp[i][sum_w]);
        }
    }
    cout << dp[n][w] << endl;

    return 0;
}