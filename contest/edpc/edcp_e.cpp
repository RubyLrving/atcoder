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
    ll max_v = 0;
    rep(i, n){
        cin >> w_list[i] >> v_list[i];
        max_v += v_list[i];
    }

    rep(i, 110) rep(j, 100010) dp[i][j] = INF;
    dp[0][0] = 0;

    for(int i=0; i<n; i++){
        for(int sum_v=0; sum_v<=max_v; sum_v++){
            if(sum_v - v_list[i] >= 0){
                chmin(dp[i+1][sum_v], dp[i][sum_v - v_list[i]] + w_list[i]);
            }
            chmin(dp[i+1][sum_v], dp[i][sum_v]);
        }
    }

    ll res = 0;
    for(int sum_v=0; sum_v<=max_v; sum_v++){
        if(dp[n][sum_v] <= w) res = sum_v;
    }
    cout << res << endl;

    return 0;
}