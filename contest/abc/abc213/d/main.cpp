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

vector<int> root;

void dfs(int p, int q, vector<vector<int>> &graph){

    root.push_back(p);

    for(auto g:graph[p]){
        if(g == q) continue;
        dfs(g, p, graph);
        root.push_back(p);
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>());

    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(0, -1, graph);

    for(auto r:root){
        cout << r + 1 << ' ';
    }

    return 0;
}