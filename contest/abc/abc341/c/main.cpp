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

int H, W, N;
string T;
string HW[501];
int ans;

void move(int y, int x){
    
    if(HW[y][x]=='#') return;

    rep(i, N){
        switch (T[i])
        {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'D':
            y++;
            break;
        case 'U':
            y--;
            break;
        default:
            break;
        }

        if(y<0 || H<=y || x<0 || W<=x) return;
        if(HW[y][x]=='#') return;
    }
    ans++;
}

int main() {
    cin >> H >> W >> N;
    cin >> T;
    rep(i, H) cin >> HW[i];
    rep(i, H) rep(j, W) move(i, j);
    cout << ans << endl;
    return 0;
} 