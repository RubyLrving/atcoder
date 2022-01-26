#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9
 
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    ll N;
    cin >> N;

    map<ll, ll> mp;
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        mp[a] += 1;
        mp[a+b] += -1;
    }

    ll s=0, t=0;
    vector<ll> vec(N+1);
    for(auto m:mp){
        ll p = m.first - s;
        vec[t] += p;
        s = m.first;
        t += m.second;
    }

    for(int i=1; i<vec.size(); i++){
        cout << vec[i];
        if(i != vec.size()-1) cout << " ";
    }

    return 0;
}