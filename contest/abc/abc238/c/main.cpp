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

ll amari = 998244353;

int main() {
    ll N;
    cin >> N;
    string s = to_string(N);
    ll n = s.size();
    ll p10 = 10;
    ll ans=0;
    for(ll i=0; i<n; i++){
        ll l = p10 / 10;
        ll r = min(N, p10-1);
        ll t = (r-l+1) % amari;
        ll tt = t*(t+1)/2 % amari;
        ans = (ans+tt) % amari;
        p10*=10;
    }
    cout << ans << endl;

    return 0;
} 