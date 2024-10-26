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

void dfs(int v, int p, vector<vector<int>> &graph, vector<bool> &used){

    for(auto u:graph[v]){
        if(u == p) continue;

        dfs(u, v, graph, used);

        if(used[u]) used[v] = true;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> graph(N);
    rep(i, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> V(K);
    rep(i, K) cin >> V[i], V[i]--;
    vector<bool> used(N);
    rep(i, K) used[V[i]] = true;

    dfs(V[0], -1, graph, used);

    int ans = 0;
    for(auto u:used) if(u) ans++;
    cout << ans << endl;
    
    return 0;
} 