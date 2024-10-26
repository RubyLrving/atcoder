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

int dx[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
string snuke = "snuke";
int H, W;
vector<string> S;

int checkSnuke(int w, int h, int cnt, int ddx, int ddy){
    int x = w;
    int y = h;
    for(int i=0; i<5; i++){
        if(x<0 || W <= x || y<0 || H <= y){
            return 0;
        }
        if(S[y][x] == snuke[cnt]){
            cnt++;
            x+=ddx;
            y+=ddy;
        }else{
            return 0;
        }
    }
    return 1;
}

int main() {
    cin >> H >> W;

    S.resize(H);
    rep(i, H) cin >> S[i];

    for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
            for(int i=0; i<8; i++){
                if(checkSnuke(w, h, 0, dx[i], dy[i])){
                    int ddx = w+1;
                    int ddy = h+1;
                    for(int j=0; j<5; j++){
                        cout << ddy << ' ' << ddx << endl;
                        ddx = ddx + dx[i];
                        ddy = ddy + dy[i];
                    }   
                }
            }
        }
    }

    return 0;
} 