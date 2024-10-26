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
    ll N;
    cin >> N;
    vector<ll> A(N), S(N+1);
    rep(i, N) cin >> A[i];
    rep(i, N) S[i+1] = S[i] ^ A[i];

    ll ans = 0;
    for(ll k=0; k < 30; k++){
        ll one = 0;
        rep(i, N+1) if(S[i]>>k&1) one++;
        ans += one * (N+1-one) * (1 << k);
    }
    rep(i, N) ans -= A[i];
    cout << ans << endl;

    return 0;
} 