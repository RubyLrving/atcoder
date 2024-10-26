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

int main() {
    ll N, M, all=0;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    map<ll, ll> mp;
    rep(i, N){
        ll a = A[i] % M;
        mp[a] += A[i];
        all += A[i];
    }

    ll cnt=0;
    ll old=0;
    if(mp.find(0) == mp.end()) old = mp.begin()->first;
    vector<ll> res(1, 0);
    for(auto m:mp){
        if(old == m.first || old+1 == m.first) res[cnt] += m.second;
        else cnt++, res.push_back(m.second);
        old = m.first;
    }
    ll ans=0;
    for(auto r:res){
        ans = max(ans, r);
    }
    if(mp.find(0) != mp.end() && res.size() > 1) ans = max(ans, res[0] + res[cnt]);
    cout << all - ans << endl;

    return 0;
} 