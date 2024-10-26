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

void dfs(int x, vector<vector<int>> graph, vector<int> check){
    if(check[x] == 1){
        return;
    }
    check[x] = 1;
    for(int j=0; j<graph[x].size(); j++){
        dfs(graph[x][j], graph, check);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph;
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    rep(i, N){
        int cnt=0;
        vector<int> check(N, 0);

        dfs(i, graph, check);
    }

    return 0;
}