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
    int N, M;
    cin >> N >> M;
    vector<vector<pair<ll, ll>>> graph(N);
    rep(i, M){
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, -w});
    }

    vector<ll> cost(N, 0);
    vector<bool> used(N, false);
    for(int i=0; i<N; i++){
        if(used[i]) continue;

        used[i] = true;
        queue<int> que;
        que.push(i);

        while(que.size()){
            int p = que.front();
            que.pop();
            for(auto g:graph[p]){
                if(used[g.first] == false){
                    used[g.first] = true;
                    cost[g.first] = cost[p] + g.second;
                    que.push(g.first);
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        cout << cost[i];
        if(i<N-1) cout << ' ';
        else cout << endl;
    }

    return 0;
}