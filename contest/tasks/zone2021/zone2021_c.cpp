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

int main() {
    ll n;
    cin >> n;
    
    vector<ll> a(n), b(n), c(n), d(n), e(n), res(n);

    ll m=100000007;
    for(ll i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
        res[i] = min(m, min(a[i], min(b[i], min(c[i], min(d[i], e[i])))));
    }

    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    cout << res[2] << endl;

    return 0;
}