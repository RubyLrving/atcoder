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
    int H, W, D;
    cin >> H >> W >> D;
    string S[10];
    rep(i, H) cin >> S[i];

    int ans = 0;
    rep(y1, H) rep(x1, W){
        if(S[y1][x1] == '#') continue;
        rep(y2, H) rep(x2, W){
            if(S[y2][x2] == '#') continue;
            if(y1==y2 && x1==x2) continue;
            int cnt=0;
            rep(i, H) rep(j, W){
                if(S[i][j] == '#') continue;
                bool ok = false;
                if(abs(y1 - i) + abs(x1 - j) <= D) ok=true;
                if(abs(y2 - i) + abs(x2 - j) <= D) ok=true;
                if(ok) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
} 
