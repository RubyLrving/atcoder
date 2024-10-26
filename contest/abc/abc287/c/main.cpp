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

    vector<vector<int>> graph(N, vector<int>());
    vector<bool> check(N, false);
    rep(i, M){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(M != N - 1){
        cout << "No" << endl;
        return 0;
    }

    rep(i, N){
        if(graph[i].size()>2){
            cout << "No" << endl;
            return 0;
        }
    }

    queue<int> que;
    que.push(0);

    while(que.size()){
        int p = que.front();
        que.pop();

        if(check[p]) continue;
        check[p] = true;

        for(auto g:graph[p]){
            que.push(g);
        }
    }

    for(auto c:check){
        if(!c){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
} 