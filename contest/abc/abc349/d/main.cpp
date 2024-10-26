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

set<pair<ll, ll>> st;

void dfs(ll l, ll r, ll L, ll R){
    if(L <= l && r <= R){
        st.insert(pair<ll, ll>(l, r));
        return;
    }
    ll m = (l + r) / 2;
    if(R<=m){
        dfs(l, m, L, R);
        return;
    }
    if(m<=L){
        dfs(m, r, L, R);
        return;
    }
    dfs(l, m, L, R);
    dfs(m, r, L, R);
}


int main() {
    ll L, R;
    cin >> L >> R;
    ll m = 1;
    rep(i, 60) m *= 2;
    dfs(0, m, L, R);
    cout << st.size() << endl;
    for(auto s:st){
        cout << s.first << ' ' << s.second << endl;
    }
    return 0;
} 