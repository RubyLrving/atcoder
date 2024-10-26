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

ll N;
ll D[17][17];
ll ans=0;
bool used[17];

void dfs(ll p, ll sum){

    if(p>=N){
        ans = max(ans, sum);
        return;
    }

    dfs(p+1, sum);

    if(used[p]) return;

    used[p] = true;

    for(int i=p+1; i<=N; i++){
        if(used[i]) continue;
        used[i] = true;
        dfs(p+1, sum + D[p][i]);
        used[i] = false;
    }

    used[p] = false;
}

int main() {
    cin >> N;

    repx(i, 1, N+1){
        repx(j, i+1, N+1){
            cin >> D[i][j];
        }
    }
    dfs(1, 0);
    cout << ans << endl;

    return 0;
} 