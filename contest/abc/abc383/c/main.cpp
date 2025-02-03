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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    const int INF = 100100100;
    vector<vector<int>> dist(H, vector<int>(W, INF));

    queue<P> que;
    rep(y, H) rep(x, W){
        if(S[y][x] == 'H'){
            dist[y][x] = 0;
            que.push({x, y});
        }
    }

    while(que.size()){
        auto [x, y] = que.front();
        que.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || W<=nx || ny<0 || H<=ny) continue;
            if(S[ny][nx] == '#') continue;
            if(dist[ny][nx] != INF) continue;            
            dist[ny][nx] = dist[y][x] + 1;
            que.push({nx, ny});
        }
    }

    int ans = 0;
    rep(y, H) rep(x, W) if(dist[y][x] <= D) ans++;
    cout << ans << endl;

    return 0;
} 
