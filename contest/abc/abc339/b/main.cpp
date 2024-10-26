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

int HW[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    int d = 0, x=0, y=0;
    rep(i, N){
        if(HW[y][x] == 0){
            HW[y][x] = 1;
            d++;
        }else{
            HW[y][x] = 0;
            d--;
        }
        if(d>=4) d=0;
        if(d<0) d=3;
        x += dx[d];
        y += dy[d];
        if(x>=W) x=0;
        if(y>=H) y=0;
        if(x<0) x=W-1;
        if(y<0) y=H-1;
    }

    rep(i, H){
        rep(j, W){
            if(HW[i][j]) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }


    return 0;
} 