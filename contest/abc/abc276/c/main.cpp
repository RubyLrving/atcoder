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

ll dfs(ll N){
    if(N<=0) return 0;
    if(N==1) return 1;
    return N * dfs(N-1);
}

void solve(ll N, vector<ll> P){
    prev_permutation(P.begin(), P.end());
    rep(i, N){
        cout << P[i];
        if(i < N - 1) cout << ' ';
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> P(N);
    rep(i, N) cin >> P[i];
    solve(N, P);
    return 0;
} 