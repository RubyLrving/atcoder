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
using P = pair<ll,ll>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

// 辺情報を表す構造体
struct edge {
    ll to;     // 辺の終点
    ll leng;   // 辺の重み
};

const ll INF = 2e18;    // 初期化で使う十分大きな数

int main() {
        // 入力を受け取る
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<edge>> G(N);  // G[i]：頂点 i を始点とする辺情報を格納する
    for(int i = 0; i < M; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v, w + A[v]});
        G[v].push_back({u, w + A[u]});
    }

    vector<ll> dist(N, INF);        // dist[i]：頂点 0 から頂点 i への暫定的な経路長
    vector<bool> done(N, false);    // done[i]：頂点 i の最短距離が確定しているか
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(0, 0));
    dist[0] = 0;

    while(que.size()) {
        ll d = que.top().first;
        ll i = que.top().second;
        que.pop();

        if (done[i]) continue;
        done[i] = true;

        for(auto e : G[i]) {
            if(dist[e.to] > dist[i] + e.leng){
                dist[e.to] = dist[i] + e.leng;
                que.push(make_pair(dist[e.to], e.to));
            }
        }
    }

    // 答えを出力する
    for(int i = 1; i < N; ++i) {
        cout << dist[i] + A[0] << ' ';
    }
    cout << endl;

	return 0;
} 