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

int N, M;
int field[400][400] = {1000000007};

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
const long long INF = 1LL << 60;

ll f(int s, int t, int k){
    vector<long long> dis(N);
    priority_queue<P, vector<P>, greater<P>> pq;  // 「仮の最短距離, 頂点」が小さい順に並ぶ
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {  // 最短距離で無ければ無視
            continue;
        }
        for (int i=0; i<N-1; i++) {
            if (dis[i] > dis[v] + field[v][i]) {  // 最短距離候補なら priority_queue に追加
                dis[i] = dis[v] + field[v][i];
                if(i == s || i == t || i < k) pq.emplace(dis[i], i);
            }
        }
    }
    return dis[t]==INF? 0:dis[t];
}

int main() {
    
    cin >> N >> M;

    for(int i=0; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        field[a-1][b-1] = c;
    }

    ll value=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                value += f(i, j, k);
            }
        }
    }
    cout << value << endl;

    return 0;
}