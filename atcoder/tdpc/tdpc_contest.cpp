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

bool dp[110][10010];

int main() {
    int n;
    cin >> n;

    vector<int> p(n+1);
    int sum_value=0;
    rep(i, n){
        cin >> p[i+1];
        sum_value += p[i+1];
    }

    dp[0][0]=true;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum_value; j++){
            if(dp[i-1][j]){
                dp[i][j]=true;
                dp[i][j+p[i]]=true;
            }
        }
    }

    int res=0;
    for(int i=0; i<=sum_value; i++){
        if(dp[n][i]) res++;
    }
    cout << res << endl;
    return 0;
}