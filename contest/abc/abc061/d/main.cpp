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

struct Eage {
    ll from;
    ll to;
    ll cost;
};

ll INF = 2e18;

void ShortsetPath(int s, int v, int m, vector<Eage> &graph, vector<ll> &d){
    d[s] = 0;

    for(int i=0; i<v-1; i++){
        for(int j=0; j<m; j++){
            Eage e = graph[j];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<Eage> graph;
    rep(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        Eage e;
        e.from = a - 1;
        e.to = b - 1;
        e.cost = -c;
        graph.push_back(e);
    }
    vector<ll> d(N, INF);
    ShortsetPath(0, N, M, graph, d);
    ll ans = -d[N-1];

    vector<bool> negative(N, false);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            Eage e = graph[j];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                negative[e.to] = true;
            }

            if(negative[e.from] == true){
                negative[e.to] = true;
            }
        }
    }

    if(negative[N-1]) cout << "inf" << endl;
    else cout << ans << endl;

    return 0;
} 