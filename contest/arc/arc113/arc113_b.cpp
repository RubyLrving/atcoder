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

ll modPow(ll a, ll n, ll mod){
    ll res = 1;
    while(n>0){
        if(n&1) res = res * a % mod;
        a = a * a % mod;
        n = n>>1;
    }
    return res;
}

void solve(ll a, ll b, ll c){
    ll n = modPow(b, c, 4)+4;
    ll res = modPow(a, n, 10);
    cout << res << endl;
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}