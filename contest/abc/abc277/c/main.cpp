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
    int N;
    cin >> N;
    map<int, vector<int>> graph;
    rep(i, N){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> que;
    que.push(1);
    set<int> st;
    int ans=1;
    while(que.size()){
        int p = que.front();
        que.pop();
        if(graph.find(p) == graph.end()) continue;
        int n = graph[p].size();
        rep(i, n){
            int q = graph[p][i];
            if(st.find(q) != st.end()) continue;
            st.insert(q);
            que.push(q);
            ans = max(ans, q);
        }
    }
    cout << ans << endl;

    return 0;
} 