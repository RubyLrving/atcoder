#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
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

char field[100][100];

int main() {
    int H, W, X, Y;
    cin >> H >> W >> Y >> X;

    for(int x=0; x<H; x++){
        string s;
        cin >> s;
        for(int y=0; y<W; y++) field[x][y] = s[y];
    }

    int res=0;
    if(field[Y-1][X-1] == '.') res++;

    for(int x=X; x<W&&field[Y-1][x] == '.'; x++) res++;

    for(int x=X-2; x>=0&&field[Y-1][x] == '.'; x--) res++;

    for(int y=Y; y<H&&field[y][X-1] == '.'; y++) res++;

    for(int y=Y-2; y>=0&&field[y][X-1] == '.'; y--) res++;

    cout << res << endl;

    return 0;
}