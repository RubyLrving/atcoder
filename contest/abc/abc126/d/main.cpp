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

struct Eage{
    int to;
    int cost;
    Eage(int to_, int cost_): to(to_), cost(cost_) {}
};

int main() {
    int N;
    cin >> N;

    vector<vector<Eage>> graph(N);
    for(int i=0; i<N-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back(Eage(v, w));
        graph[v].push_back(Eage(u, w));
    }

    vector<int> color(N, -1);
    queue<int> que;
    que.push(0);
    color[0] = 0;

    while(que.size()){
        int p = que.front();
        que.pop();

        for(auto g:graph[p]){

            if(color[g.to] != -1) continue;
            if(g.to == p) continue;

            if(g.cost % 2 == 1){
                color[g.to] = 1 - color[p];
            }else{
                color[g.to] = color[p];
            }

            que.push(g.to);
        }
    }

    for(int i=0; i<N; i++){
        cout << color[i] << endl;
    }

    return 0;
} 