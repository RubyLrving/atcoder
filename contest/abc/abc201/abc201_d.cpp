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

int H, W;
char A[2001][2001];
int cost[2001][2001];
int dp[2001][2001];

void solve(){

    if(H==1&&W==1){ cout << "Draw" << endl; return; }

    for(int h=H-1; h>=0; h--){
        for(int w=W-1; w>=0; w--){
            if((h+w)%2==0){
                if(h+1<H && w+1<W) dp[h][w] = max(dp[h+1][w] + cost[h+1][w], dp[h][w+1] + cost[h][w+1]);
                if(h+1>=H && w+1<W) dp[h][w] = dp[h][w+1] + cost[h][w+1];
                if(h+1<H && w+1>=W) dp[h][w] = dp[h+1][w] + cost[h+1][w];
            }else{
                if(h+1<H && w+1<W) dp[h][w] = min(dp[h+1][w] - cost[h+1][w], dp[h][w+1] - cost[h][w+1]);
                if(h+1>=H && w+1<W) dp[h][w] = dp[h][w+1] - cost[h][w+1];
                if(h+1<H && w+1>=W) dp[h][w] = dp[h+1][w] - cost[h+1][w];
            }
        }
    }

    if(dp[0][0]>0) cout << "Takahashi" << endl;
    if(dp[0][0]<0) cout << "Aoki" << endl;
    if(dp[0][0]==0) cout << "Draw" << endl;
}

int main() {
    
    cin >> H >> W;

    rep(i, H) rep(j, W) cin >> A[i][j];
    rep(i, H+1) rep(j, W+1){
        if(A[i][j] == '+') cost[i][j] = 1;
        else if(A[i][j] == '-') cost[i][j] = -1;
        else cost[i][j] = 0;
    }

    solve();

    return 0;
}