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
using P = pair<int,string>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int previous[200010];

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    // 経路を保持のする配列を-1で初期化
    rep(i, N+1) previous[i] = -1;
    // 無向グラフの作成
    vector<vector<int>> graph(N+1);
    rep(i, N-1){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // bfs
    queue<int> que;
    que.push(X);
    previous[X] = 0;
    while(que.size()){
        int p = que.front();
        que.pop();
        //処理に適した繰り返し処理
        for(auto g:graph[p]){
            //キューに追加する条件
            if(previous[g] >= 0) continue;
            //どの経路をきたか保持
            previous[g] = p;
            //キューに追加
            que.push(g);
        }
    }
    // ゴールからXまでの経路を復元
    int current = Y;
    vector<int> res;
    while (current != 0) {
        res.push_back(current);
        current = previous[current];
    }
    reverse(res.begin(), res.end());
    // 解答を出力
    for(int i=0; i<res.size(); i++){
        cout << res[i];
        if(res.size()-1 > i) cout << ' ';
    }
    cout << endl;

    return 0;
} 