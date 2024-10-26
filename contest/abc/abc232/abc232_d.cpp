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

char graph[101][101];
int dist[101][101];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main() {
    int H, W;
    cin >> H >> W;

    rep(y, H){
        rep(x, W){
            cin >> graph[y][x];
        }
    }

    queue<P> que;
    que.push(P(0,0));
    dist[0][0] = 1;

    int res=1;
    while(que.size()){
        P p = que.front();
        que.pop();
        for(int i=0; i<2; i++){
            //何かしらの処理
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(W<=nx || H<=ny) continue;

            //キューに追加する条件
            if(graph[ny][nx] == '.' && dist[ny][nx] == 0){
                //何かしらの処理
                dist[ny][nx] = dist[p.first][p.second] + 1;
                //キューに追加
                que.push(P(ny, nx));

                res = max(res, dist[ny][nx]);
            }
        }
    }
    cout << res << endl;

    return 0;
}