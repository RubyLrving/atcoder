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
    int N = 8;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    
    int graph[8][8];
    memset(graph, 0, sizeof(graph));
    auto used = [](const int x, const int y, int (&graph)[8][8]){
        for(int i=0; i<8; i++){
            graph[y][i] = 1;
            graph[i][x] = 1;
        }
    };

    rep(i, N){
        rep(j, N){
            if(S[i][j] == '#'){
                used(j, i, graph);
            }
        }
    }

    int ans = 0;
    rep(i, N){
        rep(j, N){
            if(graph[i][j] == 0) ans++;
        }
    }
    cout << ans << endl;

    return 0;
} 