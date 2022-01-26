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

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};
char S[10][10];

int main() {
    int h, w;
    cin >> h >> w;

    for(int y=0; y<h; y++){
        for(int x=0; x<w; x++){
            cin >> S[y][x];
        }
    }

    int res = 0;
    for(int y=0; y<h-1; y++){
        for(int x=0; x<w-1; x++){

            int cnt=0;
            for(int i=0; i<4; i++){
                int ddx = x + dx[i];
                int ddy = y + dy[i];
                if(S[ddy][ddx] == '#') cnt++;
            }

            if(cnt==3 or cnt==1) res++;
        }
    }
    cout << res << endl;

    return 0;
}