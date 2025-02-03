#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];

    int ans = 0;
    rep(i, N) rep(j, N){
        int ok = 1;
        rep(y, M) rep(x, M){
            if(i+y>=N || j+x>=N){
                ok = 0;
                continue;
            }
            if(S[i+y][j+x] != T[y][x]){
                ok = 0;
            }
        }
        if(ok){
            cout << i+1 << ' ' << j+1 << endl;
            return 0;
        }
    }

    return 0;
} 
