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
    int Mg, Mh;
    cin >> Mg;
    bool G[30][30], H[30][30];
    rep(i, 30) rep(j, 30) G[i][j] = false;
    rep(i, 30) rep(j, 30) H[i][j] = false;
    int A[30][30];
    rep(i, 30) rep(j, 30) A[i][j] = 0;
    rep(i, Mg){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u][v] = true;
        G[v][u] = true;
    }
    cin >> Mh;
    rep(i, Mh){
        int a, b;
        cin >> a >> b;
        a--, b--;
        H[a][b] = true;
        H[b][a] = true;
    }
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    vector<int> P;
    rep(i, N) P.push_back(i);

    int ans = 1e9;
    do {
        int cost = 0;
        for(int u=0; u<N; u++){
            for(int v=u+1; v<N; v++){
                int a = P[u];
                int b = P[v];
                if(G[u][v] != H[a][b]){
                    cost += A[a][b];
                }
            }
        }
        ans = min(ans, cost);
    }while(next_permutation(P.begin(), P.end()));

    cout << ans << endl;
    return 0;
} 