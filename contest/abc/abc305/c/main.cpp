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
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    rep(i, H) cin >> grid[i];

    int ok=0, hcnt=0, hhcnt=0, wcnt=0, wwcnt=0;
    rep(i, H){
        int cnt=0;
        rep(j, W){
            if(grid[i][j] == '.') cnt++;
            else ok=1;
        }
        if(cnt == W && !ok){
            hcnt++;
        }else if(cnt == W){
            hhcnt++;
        }
    }
    ok=0;
    rep(i, W){
        int cnt=0;
        rep(j, H){
            if(grid[j][i] == '.') cnt++;
            else ok=1;
        }
        if(cnt == H && !ok){
            wcnt++;
        } else if(cnt == H){
            wwcnt++;
        }
    }

    repx(i, hcnt, H-hhcnt){
        repx(j, wcnt, W-wwcnt){
            if(grid[i][j] == '.'){
                cout << i  + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
} 