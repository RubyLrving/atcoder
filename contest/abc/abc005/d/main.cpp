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
    int N, Q;
    cin >> N;
    vector<vector<int>> D(N, vector<int>(N, 0));
    rep(i, N) rep(j, N) cin >> D[i][j];
    cin >> Q;
    vector<int> P(Q);
    rep(i, Q) cin >> P[i];

    vector<vector<int>> DD(N+2, vector<int>(N+2, 0));
    rep(i, N) rep(j, N) DD[i+1][j+1] = D[i][j];
    rep(i, N+1) rep(j, N+1) DD[i][j+1] += DD[i][j];
    rep(i, N+1) rep(j, N+1) DD[i+1][j] += DD[i][j];

    rep(i, Q){
        int ans = 0;
        for(int y1=0; y1<N; y1++) for(int x1=0; x1<N; x1++) {
            for(int y2=y1+1; y2<N+1; y2++) for(int x2=x1+1; x2<N+1; x2++) {
                if((y2 - y1) * (x2 - x1) <= P[i]){
                    int sum = DD[y2][x2] - DD[y1][x2] - DD[y2][x1] + DD[y1][x1];
                    ans = max(ans, sum);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
} 