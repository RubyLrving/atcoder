#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
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

int dp[100000][100000] = {1000000007};
int bridge[100000][100000] = {1000000007};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> bridge(N); 
    rep(i, N-1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        bridge[a][b]=1;
        bridge[b][a]=1;
    }

    rep(cnt, Q){
        int c, d;
        cin >> c >> d;
        for(int k = 0; k < N; k++) {
            for(int i = c; i < N; i++) {
                for(int j = d; j < N; j++) {
                    dp[i][j] = min(dp[i][j], bridge[i][k] + bridge[k][j]);
                }
            }
        }
        if(dp[c][d]%2==0) cout << "Town" << endl;
        else cout << "Road" << endl;
    }

    return 0;
}