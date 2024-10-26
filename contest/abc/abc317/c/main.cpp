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

ll ans = 0;
vector<vector<pair<ll, ll>>> graph;
vector<bool> used;

void dfs(int p,ll cost){

    used[p] = true;

    ans = max(ans, cost);

    for(auto g:graph[p]){
        if(used[g.first] == false){
            dfs(g.first, cost + g.second);
        }
    }

    used[p] = false;
}

int main() {
    ll N, M;
    cin >> N >> M;

    graph.resize(N);
    used.resize(N, false);
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back(pair<ll, ll>(b, c));
        graph[b].push_back(pair<ll, ll>(a, c));
    }

    for(int i=0; i<N; i++){
        dfs(i, 0);
    }

    cout << ans << endl;

    return 0;
} 