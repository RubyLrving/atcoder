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

ll N, M, A, B, C, D, E, F;
map<pair<ll, ll>, ll> mp;
set<pair<ll, ll>> st;

void dfs(ll x, ll y, ll n){

    if(st.find(make_pair(x, y)) != st.end()) return;
    if(n>N) return;

    if(mp.find(make_pair(x, y)) == mp.end()){
        mp[make_pair(x, y)] = 1;

        dfs(x+A, y+B, n+1);
        dfs(x+C, y+D, n+1);
        dfs(x+E, y+F, n+1);
    }else{
       mp[make_pair(x, y)] += 1;
       mp[make_pair(x, y)] = mp[make_pair(x, y)] % 998244353;
    }
}

int main() {

    cin >> N >> M;
    cin >> A >> B >> C >> D >> E >> F;


    for(int i=0; i<M; i++){
        ll x, y;
        cin >> x >> y;
        st.insert(P(x, y));
    }

    dfs(A, B, 1);
    dfs(C, D, 1);
    dfs(E, F, 1);

    ll ans=0;
    for(auto &m:mp){
        ans += m.second;
        ans = ans % 998244353;
    }
    cout << ans << endl;

    return 0;
} 