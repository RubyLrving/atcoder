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

int graph[9][9];
set<pair<vector<int>, int>> st;
int res=0;



int main() {
    int m;
    cin >> m;

    rep(i, m){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    vector<int> p(9);
    rep(i, 9) p[i] = -1;
    rep(i, 8){
        int t;
        cin >> t;
        p[t-1] = i; 
    }

    int start = 0;
    rep(i, 9) if(p[i] == -1) start=i;
    queue<pair<vector<int>, int>> que;

    que.push(pair<vector<int>, int>(p, 0));

    while(que.size()){
        pair<vector<int>, int> q = que.front();
        que.pop();

        if(st.find(q) != st.end()) continue;
        st.insert(q);

        int sum=0;
        rep(i, 8) if(q.first[i] == i) sum++;
        if(sum==8){
            cout << q.second << endl;
            return 0;
        }    

        rep(i, 9) if(q.first[i] == -1) start=i;
        rep(i, 9){
            if(graph[start][i]){
                pair<vector<int>, int> t=q;
                swap(t.first[i], t.first[start]);
                t.second++;
                que.push(t);
            }
        }
    }

    cout << -1 << endl;

    return 0;
}