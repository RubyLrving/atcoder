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

char S[200][200];
char T[200][200];
char Tmp[200][200];

template <size_t N, size_t M>
int OffsetPos(int& x, int& y, char (&tmp)[N][M]){
    rep(i, N){
        rep(j, N){
            if(tmp[i][j] == '#'){
                x = j;
                y = i;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int N;
    cin >> N;

    rep(i, N) rep(j, N) cin >> S[i][j]; 
    rep(i, N) rep(j, N) cin >> T[i][j];

    int cntS=0;
    int cntT=0;
    rep(i, N) rep(j, N){
        if(S[i][j]=='#') cntS++;
        if(T[i][j]=='#') cntT++;
    }

    if(cntT != cntS){
        cout << "No" << endl;
        return 0;
    }

    rep(i, 4){
        switch (i)
        {
        case 0:
            /* code */
            rep(y, N) rep(x, N) Tmp[y][x] = T[y][x];
            break;
        case 1:
            /* code */
            rep(y, N) rep(x, N) Tmp[y][x] = T[N-1-x][y];
            break;
        case 2:
            /* code */
            rep(y, N) rep(x, N) Tmp[y][x] = T[N-1-y][N-1-x];
            break;
        case 3:
            /* code */
            rep(y, N) rep(x, N) Tmp[y][x] = T[x][N-1-y];
            break;
        
        default:
            break;
        }

        int x1, y1, x2, y2, offset_x, offset_y;
        if(OffsetPos(x1, y1, S)){
            if(OffsetPos(x2, y2, Tmp)){
                int isOK = 1;
                offset_x = x2 - x1;
                offset_y = y2 - y1;

                rep(y, N) rep(x, N){
                    if(x+offset_x >= N || y+offset_y >= N || x+offset_x < 0 || y+offset_y < 0){
                        if(S[y][x] == '#'){
                            isOK = 0;
                            break;
                        }else continue;
                    }

                    if(S[y][x] != Tmp[y+offset_y][x+offset_x]){
                        isOK = 0;
                        break;
                    }
                }

                if(isOK){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}