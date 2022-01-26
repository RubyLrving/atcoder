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

void solve(ll N, map<ll, ll> m){
    ll res=0;
    for(int i=0; i<200; i++){
        if(m[i]<2) continue;
        res += ((m[i]-1) * m[i]) / 2;
    }
    cout << res << endl;
}

int main() {
    ll N;
    cin >> N;
    map<ll, ll> m;
    rep(i, N){
        ll t;
        cin >> t;
        m[t%200]++;
    }
    solve(N, m);

    return 0;
}