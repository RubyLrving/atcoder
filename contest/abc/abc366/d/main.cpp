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

int A[101][101][101];
int S[101][101][101];

int main() {
    int N;
    cin >> N;
    rep(i, N) rep(j, N) rep(k, N) cin >> A[i][j][k];

    rep(i, N) rep(j, N) rep(k, N) S[i+1][j+1][k+1] = A[i][j][k];

    rep(i, N+1) rep(j, N+1) rep(k, N+1) S[i+1][j][k] += S[i][j][k];
    rep(i, N+1) rep(j, N+1) rep(k, N+1) S[i][j+1][k] += S[i][j][k];
    rep(i, N+1) rep(j, N+1) rep(k, N+1) S[i][j][k+1] += S[i][j][k];
    
    int Q;
    cin >> Q;
    vector<int> Lx(Q), Rx(Q), Ly(Q), Ry(Q), Lz(Q), Rz(Q);
    rep(i, Q) cin >> Lx[i] >> Rx[i] >> Ly[i] >> Ry[i] >> Lz[i] >> Rz[i];

    rep(i, Q){
        int lx = Lx[i] - 1;
        int rx = Rx[i];
        int ly = Ly[i] - 1;
        int ry = Ry[i];
        int lz = Lz[i] - 1;
        int rz = Rz[i];

        int ans = S[rx][ry][rz]
         - S[lx][ry][rz] - S[rx][ly][rz] + S[lx][ly][rz]
         - S[rx][ry][lz] + S[rx][ly][lz] + S[lx][ry][lz]
         - S[lx][ly][lz];
        cout << ans << endl;
    }
    
    return 0;
} 

