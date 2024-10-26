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

ll dp[2000][2000];
ll XCNT[2000][2000];
int ok[2000];
ll MOD = 998244353;

int main() {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    S--;
    T--;
    vector<vector<int>> graph(N);
    rep(i, M){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dp[0][S] = 1;
    for(int i=1; i<K; i++){
        for(int j=0; j<N; j++){
            for(auto g:graph[j]){
                dp[i][g] = (dp[i][g] + dp[i-1][g]) % MOD;
                if(g==X) XCNT[i][g] = XCNT[i-1][g] + 1;
            } 
        } 
    }
    cout << dp[K-1][T] << endl;

    return 0;
} 