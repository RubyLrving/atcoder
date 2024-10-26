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

ll res=0;

void dfs(ll X, vector<vector<ll>> a, int cnt){
    if(a.size()<=cnt){
        if(X==1) res++;
        return;
    }

    int n = a[cnt].size();

    rep(i, n){
        if(X%a[cnt][i] == 0) dfs(X/a[cnt][i], a, cnt+1);
    }
}

int main() {
    ll N, X;
    cin >> N >> X;

    vector<vector<ll>> a(N);
    rep(i, N){
        int l;
        cin >> l;

        a[i].resize(l);
        rep(j, l) cin >> a[i][j];
    }

    dfs(X, a, 0);

    cout << res << endl;

    return 0;
}