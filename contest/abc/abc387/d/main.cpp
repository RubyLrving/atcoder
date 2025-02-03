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

int INF = 1e9;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    int h, w;
    rep(i, H) rep(j, W){
        if(S[i][j] == 'S'){
            h = i;
            w = j;
        }
    }

    vector<vector<pair<int, int>>> moves(2);
    moves[0] = {{0, 1}, {0, -1}};
    moves[1] = {{1,  0}, {-1, 0}};
    int ans = INF;
    rep(p, 2){
        queue<pair<int, int>> que;
        vector<vector<int>> used(H, vector<int>(W, INF));
        used[h][w] = 0;
        que.push({w, h});
        int d = INF;
        while(que.size()){
            auto [x, y] = que.front();
            que.pop();

            for(auto [dx, dy]:moves[(x+y+p)&1]){
                int xx = x + dx;
                int yy = y + dy;

                if(xx<0 || W<=xx || yy<0 || H<=yy) continue;
                if(S[yy][xx] == '#') continue;
                if(used[yy][xx] < INF) continue;

                used[yy][xx] = used[y][x] + 1;  

                if(S[yy][xx] == 'G'){
                    d = min(d, used[yy][xx]);
                }

                que.push({xx, yy});
            }
        }
        ans = min(d, ans);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
} 
