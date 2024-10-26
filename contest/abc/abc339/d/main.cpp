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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int HW[61][61];
P HW1[61][61];
P HW2[61][61];

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<P> p;
    rep(i, N) rep(j, N){
        if(S[i][j] == 'P'){
            p.push_back(P(i, j));
        }
        HW1[i][j] = P(-1, -1);
        HW2[i][j] = P(-1, -1);
    }

    //Queueを生成
    queue<P> que;
    //最初の要素をキューに追加
    que.push(p[0]);
    HW1[p[0].first][p[0].second] = P(0, 0);

    //キューの要素がなくまるまで処理を行う
    while(que.size()){
        //最初の要素を取り出す
        P p = que.front();
        que.pop();
        int cnt=0;
        //処理に適した繰り返し処理
        for(int i=0; i<4; i++){
            //何かしらの処理
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if(0>ny || N<=ny){ cnt++; continue; }
            if(0>nx || N<=nx){ cnt++; continue; }
            //キューに追加する条件
            if((S[ny][nx] == '.' || S[ny][nx] == 'P') && HW1[ny][nx]==P(-1,-1)){
                //何かしらの処理
                P pp = HW1[p.first][p.second];
                HW1[ny][nx] = P(pp.first + abs(dy[i]), pp.second + abs(dx[i]));
                //キューに追加
                que.push(P(ny, nx));
            }

            if(S[ny][nx] == '#') cnt++;
        }
        if(cnt>1) HW[p.first][p.second] = 1;
    }

    //最初の要素をキューに追加
    que.push(p[1]);
    HW2[p[1].first][p[1].second] = P(0, 0);

    //キューの要素がなくまるまで処理を行う
    while(que.size()){
        //最初の要素を取り出す
        P p = que.front();
        que.pop();
        //処理に適した繰り返し処理
        for(int i=0; i<4; i++){
            //何かしらの処理
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if(0>ny || N<=ny){ continue; }
            if(0>nx || N<=nx){ continue; }
            //キューに追加する条件
            if((S[ny][nx] == '.' || S[ny][nx] == 'P') && HW2[ny][nx]==P(-1,-1)){
                P pp = HW2[p.first][p.second];
                //何かしらの処理
                HW2[ny][nx] = P(pp.first + abs(dy[i]), pp.second + abs(dx[i]));
                //キューに追加
                que.push(P(ny, nx));
            }
        }
    }

    int ans = 200000000;
    rep(i, N) rep(j, N){
        if(HW[i][j] == 1 && HW1[i][j]!=P(-1,-1) && HW2[i][j]!=P(-1,-1)){
            ans = min(ans, max(HW1[i][j].first,HW2[i][j].first) + max(HW1[i][j].second,HW2[i][j].second));
        }
    }
    if(ans==200000000) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
} 