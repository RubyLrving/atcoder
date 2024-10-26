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

int HW[1000][1000];
int dx[] = {-1,  0,  1, -1,  0,  1, -1,  0,  1};
int dy[] = {-1, -1, -1,  0,  0,  0,  1,  1,  1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    int cnt = 1;
    rep(h, H){
        rep(w, W){

            if(HW[h][w]>0) continue;

            if(S[h][w] == '#'){
                queue<P> que;
                que.push(P(w,h));

                while(que.size()){
                    P p = que.front();
                    que.pop();

                    int x = p.first;
                    int y = p.second;

                    rep(i, 9){
                        int xx = x + dx[i];
                        int yy = y + dy[i];

                        if(0<=xx && xx<W && 0<=yy && yy<H){
                            if(S[yy][xx] == '#' && HW[yy][xx] == 0){
                                que.push(P(xx, yy));
                                HW[yy][xx] = cnt;
                            }
                        }
                    }
                }
                cnt++;
            }
        }
    }
    cout << cnt-1 << endl;

    return 0;
} 