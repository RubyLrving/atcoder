#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int n = 9;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            grid[i-1][j-1] = i*j;
        }
    }
    int x;
    cin >> x;
    int ans = 0;
    rep(i, n) rep(j, n){
        if(grid[i][j] != x) ans += grid[i][j];
    }
    cout << ans << endl;
    return 0;
} 
