#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }



void solve(ll r){
    
    auto f = [&](ll x, ll y) -> bool {
        x = x*2+1;
        y = y*2+1;
        return x*x+y*y <= r*r*4;
    };

    ll x = 0;
    ll ans = 0;
    for(ll y=r; y>=0; y--){
        while(f(x+1, y)) x++;
        ans += x;
    }

    cout << ans * 4 + 1 << endl;
}

int main() {
    ll R;
    cin >> R;

    solve(R);
    
    return 0;
} 
