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
int d[205][205];

int main() {
    int H, W, N;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H) cin >> A[i];

    int sx, sy, tx, ty;
    rep(i, H) rep(j, W){
        if(A[i][j] == 'S') sx = j, sy = i;
        if(A[i][j] == 'T') tx = j, ty = i;
    }

    cin >> N;
    map<P, int> mp;
    rep(i, N){
        int r, c, e;
        cin >> r >> c >> e;
        mp[P(--r, --c)] = e;
    }

    // Queueを生成
    queue<P> que;
    // 最初の要素をキューに追加
    que.push(P(sy, sx));

    // キューの要素がなくまるまで処理を行う
    while(que.size()){
        // 最初の要素を取り出す
        P p = que.front();
        que.pop();

        if(mp.find(P(p.first, p.second)) != mp.end()){
            if(d[p.first][p.second] < mp[P(p.first, p.second)]){
                d[p.first][p.second] = mp[P(p.first, p.second)];
            }
            mp[P(p.first, p.second)] = 0;
        }

        // 処理に適した繰り返し処理
        for(int i=0; i<4; i++){
            // 何かしらの処理
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];

            if(ny>=H || ny<0 || nx >= W || nx < 0 || d[p.first][p.second] <= 0 || A[ny][nx] == '#') continue;

            // キューに追加する条件
            if(A[ny][nx] == '.' && d[ny][nx] < d[p.first][p.second]){
                // キューに追加
                if(d[ny][nx] < d[p.first][p.second] - 1 || d[ny][nx]==0) que.push(P(ny, nx));
                // 何かしらの処理
                d[ny][nx] = d[p.first][p.second] - 1;
            }
            if(A[ny][nx] == 'T'){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}