#include <bits/stdc++.h>
#include <atcoder/all>
 
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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int H, W, K, ans;
vector<string> S;
int graph[10][10];

void dfs(int x, int y, int cnt){
    if(cnt >= K){
        ans++;
        return;
    }

    for(int i=0; i<4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx<0 || W<=xx || yy<0 || H<=yy) continue;
        if(graph[yy][xx]) continue;
        if(S[yy][xx] == '#') continue;

        graph[yy][xx] = true;
        dfs(xx, yy, cnt+1);
        graph[yy][xx] = false;
    }
}

int main() {
    
    cin >> H >> W >> K;
    S.resize(H);
    rep(i, H) cin >> S[i];

    rep(y, H){
        rep(x, W){
            if(S[y][x] == '#') continue;
            graph[y][x] = true;
            dfs(x, y, 0);
            graph[y][x] = false;
        }
    }
    cout << ans << endl;

    return 0;
} 