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
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
    }

    vector<int> dist(N, 1e9);
    queue<int> que;
    que.push(0);
    dist[0] = 0;

    while(que.size()){
        int p = que.front();
        que.pop();
        for(auto g:graph[p]){
            if(g == 0){
                cout << dist[p] + 1 << endl;
                return 0;
            }else if(dist[g] == 1e9){
                dist[g] = dist[p] + 1;
                que.push(g);
            }
        }
    }
    cout << -1 << endl;

    return 0;
} 