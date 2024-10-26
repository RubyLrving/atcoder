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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int d[1010][1010];

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> HW(H);
    rep(i, H) cin >> HW[i];

    ll ans = 0;
    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            if(HW[h][w] == '#' || d[h][w]>0) continue;

            queue<P> que;
            que.push(P(h, w));

            ll total = 0;

            while(que.size()){
                P p = que.front();
                que.pop();

                int ng = 0;
                // 処理に適した繰り返し処理
                for(int i=0; i<4; i++){
                    // 何かしらの処理
                    int ny = p.first + dy[i];
                    int nx = p.second + dx[i];

                    if(ny>=H || ny<0 || nx >= W || nx < 0) continue;
                    
                    if(HW[ny][nx] == '#') ng = 1;
                }

                if(ng) continue;

                // 処理に適した繰り返し処理
                for(int i=0; i<4; i++){
                    // 何かしらの処理
                    int ny = p.first + dy[i];
                    int nx = p.second + dx[i];

                    if(ny>=H || ny<0 || nx >= W || nx < 0) continue;
                    if(ny == h && nx == w) continue;
                    
                    // キューに追加する条件
                    if(HW[ny][nx] == '.'){
                        // キューに追加
                        if(d[ny][nx] == 0) que.push(P(ny, nx));
                        // 何かしらの処理
                        d[ny][nx] = d[p.first][p.second] + 1;
                        total++;
                    }
                }
            }

            ans = max(ans, total);
        }
    }
    cout << ans + 1 << endl;

    return 0;
} 