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

int H, W;
int A[11][11];
int ans;

void dfs(int y, int x, map<int, int> mp){
    mp[A[y][x]]++;

    if(y >= H-1 && x >= W-1){
        int ok = 1;
        for(auto m:mp) if(m.second>1){
            ok = 0;
        } 
        if(ok) ans++;
        return;
    }

    if(y+1<H) dfs(y+1, x, mp);
    if(x+1<W) dfs(y, x+1, mp);
}

int main() {

    cin >> H >> W;

    for(int y=0; y<H; y++){
        for(int x=0; x<W; x++){
            cin >> A[y][x];
        }
    }

    map<int, int> mp;
    dfs(0, 0, mp);

    cout << ans << endl;

    return 0;
} 