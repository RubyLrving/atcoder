#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

char field[50][50];
int dp[50][50];
int dx[4] = { 0, 1, 0, -1};
int dy[4] = {-1, 0, 1,  0};

int main(int argc, const char * argv[]) {
    int h, w;
    cin >> h >> w;

    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;

    sy--; sx--; gy--; gx--;

    rep(i, h) rep(j, w){
        cin >> field[i][j];
        dp[i][j] = -1;
    }

    queue<P> que;
    que.push(P(sx, sy));
    dp[sy][sx] = 0;

    while(que.size()){
        P p = que.front();
        que.pop();

        for(int i=0; i<4; i++){
            int x = p.first + dx[i];
            int y = p.second + dy[i];

            if(x<0 || w<=x || y<0 || h<=y) continue;

            if(field[y][x] == '.' && dp[y][x] == -1){
                dp[y][x] = dp[p.second][p.first]+1;
                que.push(P(x, y));
            }
        }
    }
    cout << dp[gy][gx] << endl;

    return 0;
}