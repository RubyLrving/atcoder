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

char G[510][510];
bool visible[510][510];

int main() {
    int H, W;
    cin >> H >> W;

    for(int i=1; i<=H; i++){
        string S;
        cin >> S;
        for(int j=1; j<=W; j++){
            G[i][j] = S[j-1];
        }
    }

    bool ok=false;
    int x=1, y=1, cnt=0;
    while(!ok){
        if(visible[y][x]){
            cout << -1 << endl;
            return 0;
        }
        visible[y][x] = true;

        if(G[y][x] == 'U' && y != 1){
            y--;
        }else if(G[y][x] == 'D' && y != H){
            y++;
        }else if(G[y][x] == 'L' && x != 1){
            x--;
        }else if(G[y][x] == 'R' && x != W){
            x++;
        }else{
            ok = true;
            break;
        }
    }

    cout << y << ' ' << x << endl;

    return 0;
} 