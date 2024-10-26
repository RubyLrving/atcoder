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

ll N, H, W, ans;
ll A[10], B[10];

int checkTilingAB(vector<vector<ll>> HW, int cnt, int x, int y){
    int ok=0;
    for(int i=0; i<A[cnt]; i++){
        for(int j=0; j<B[cnt]; j++){
            int xx = x+j;
            int yy = y+i;
            if(xx>=W || yy>=H) return 0;
            if(HW[yy][xx]==1) return 0;
        }
    }
    return 1;
}

int checkTilingBA(vector<vector<ll>> HW, int cnt, int x, int y){
    int ok=0;
    for(int i=0; i<B[cnt]; i++){
        for(int j=0; j<A[cnt]; j++){
            int xx = x+j;
            int yy = y+i;
            if(xx>=W || yy>=H) return 0;
            if(HW[yy][xx]==1) return 0;
        }
    }
    return 1;
}

int checkTiling(vector<vector<ll>> HW){
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(HW[i][j]==0) return 0;
        }
    }
    return 1;
}


void dfs(vector<vector<ll>> HW, ll cnt){

    if(N<=cnt){
        if(checkTiling(HW)){
            ans=1;
        }
        return;
    }

    vector<vector<ll>> AB(H, vector<ll>(W, 0)), BA(H, vector<ll>(W, 0));

    dfs(HW, cnt+1);

    for(int y=0; y<H; y++){
        for(int x=0; x<W; x++){
            if(HW[y][x]==0){
                if(checkTilingAB(HW, cnt, x, y)){
                    copy(HW.begin(), HW.end(), AB.begin());
                    for(int i=0; i<A[cnt]; i++){
                        for(int j=0; j<B[cnt]; j++){
                            int xx = x+j;
                            int yy = y+i;
                            AB[yy][xx]=1;
                        }
                    }
                    dfs(AB, cnt+1);
                    return;
                }
                if(checkTilingBA(HW, cnt, x, y)){
                    copy(HW.begin(), HW.end(), BA.begin());
                    for(int i=0; i<B[cnt]; i++){
                        for(int j=0; j<A[cnt]; j++){
                            int xx = x+j;
                            int yy = y+i;
                            BA[yy][xx]=1;
                        }
                    }
                    dfs(BA, cnt+1);
                    return;
                }
            }
        }
    }
}


int main() {
    cin >> N >> H >> W;
    rep(i,N) cin >> A[i] >> B[i];

    vector<vector<ll>> HW(H, vector<ll>(W, 0));
    dfs(HW, 0);

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 