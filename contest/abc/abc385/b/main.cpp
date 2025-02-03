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
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    X--; Y--;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    string T;
    cin >> T;

    int ans = 0;
    rep(i, T.size()){
        int nx = X, ny = Y;
        if('U' == T[i]) nx--;
        if('D' == T[i]) nx++;
        if('L' == T[i]) ny--;
        if('R' == T[i]) ny++;
        if(S[nx][ny] == '#') continue;
        X = nx, Y = ny;
        if(S[X][Y] == '@'){
            S[X][Y] = '.';
            ans++;
        }
    }
    cout << X+1 << ' '<< Y+1 << ' ' << ans << endl;
 
    return 0;
} 
