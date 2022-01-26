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

int graph1[8][8];
int graph2[8][8];
 
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> order(N);
    rep(i, N) order[i] = i;
 
    vector<P> graph1;
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph1.push_back(P(a,b));
    }
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph2[a][b]=1;
        graph2[b][a]=1;
    }

    int res=0;
    do{
        bool ok=true;
        /* ここにpermの処理を書く */
        for(int i=0; i<M; i++){
            int from = graph1[i].first;
            int to = graph1[i].second;

            if(graph2[order[from]][order[to]] != 1) ok=false;
        }
        if(ok) res++;
    }while(next_permutation(order.begin(), order.end()));

    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
 
    return 0;
}