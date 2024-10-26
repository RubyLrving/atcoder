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

ll INF = 2e18;

int main() {
    int N, M;
    cin >> N >> M;
    ll d[N][N];
    rep(i, N) rep(j, N) d[i][j] = INF;
    rep(i, N) d[i][i] = 0;

    rep(i, M){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = c;
    }

    ll ans = 0;
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(d[i][j] < INF) ans += d[i][j];
            }
        }
    }
    cout << ans << endl;

    return 0;
} 