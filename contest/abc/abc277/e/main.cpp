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
    int N, M, K;
    cin >> N >> M >> K;
    map<int, map<int, int>> graph;
    rep(i, M){
        int u, v, a;
        cin >> u >> v >> a;
        graph[u][v] = a;
        graph[v][u] = a;
    }
    set<int> st;
    rep(i, K){
        int s;
        cin >> s;
        st.insert(s);
    }

    queue<tuple<int, int, int>> que;
    que.push(tuple<int, int, int>(1, 0, 1));
    map<int, int> flg1, flg0;
    flg1[1] = 0; 
    while(que.size()){
        tuple<int, int, int> t = que.front();
        que.pop();
        int p = get<0>(t);
        int d = get<1>(t);
        int sw = get<2>(t);
        if(graph.find(p) == graph.end()) continue;

        for(auto m:graph[p]){
            int q = graph[p][m.first];
            int ok = 0;
            
            if(q == sw){
                if(sw==1){
                    if(flg1.find(m.first) != flg1.end()) continue;
                    flg1[m.first] = d+1;
                }else{
                    if(flg0.find(m.first) != flg0.end()) continue;
                    flg0[m.first] = d+1;
                }

                que.push(tuple<int, int, int>(m.first, d+1, sw));
            }
            if(st.find(p) != st.end()) ok = 1;
            if(q != sw && ok){
                if(sw!=1){
                    if(flg1.find(m.first) != flg1.end()) continue;
                    flg1[m.first] = d+1;
                }else{
                    if(flg0.find(m.first) != flg0.end()) continue;
                    flg0[m.first] = d+1;
                }
                que.push(tuple<int, int, int>(m.first, d+1, sw^1));
            }

        }
    }
    int ans = -1;
    if(flg1.find(N) != flg1.end()) ans = flg1[N];
    if(flg0.find(N) != flg0.end()) ans = flg0[N];
    cout << ans << endl;

    return 0;
} 