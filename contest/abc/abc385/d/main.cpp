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

int main() {
    ll n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    map<ll, set<ll>> h, w;
    rep(i, n){
        ll x, y;
        cin >> x >> y;
        w[x].insert(y);
        h[y].insert(x);
    }

    ll x = sx, y = sy;
    ll ans = 0;
    rep(i, m){
        char d;
        ll c;
        cin >> d >> c;
        if('U' == d){
            ll dy = y + c;
            auto l = w[x].lower_bound(y);
            while(l != w[x].end() && *l <= dy){
                h[*l].erase(x);
                l = w[x].erase(l);
                ans++;
            }
            y = dy;
        }
        if('D' == d){
            ll dy = y - c;
            auto l = w[x].lower_bound(dy);
            while(l != w[x].end() && *l <= y){
                h[*l].erase(x);
                l = w[x].erase(l);
                ans++;
            }
            y = dy;
        }
        if('L' == d){
            ll dx = x - c;
            auto l = h[y].lower_bound(dx);
            while(l != h[y].end() && *l <= x){
                w[*l].erase(y);
                l = h[y].erase(l);
                ans++;
            }
            x = dx;
        }
        if('R' == d){
            ll dx = x + c;
            auto l = h[y].lower_bound(x);
            while(l != h[y].end() && *l <= dx){
                w[*l].erase(y);
                l = h[y].erase(l);
                ans++;
            }
            x = dx;
        }
    }
    cout << x << ' ' << y << ' ' << ans << endl;

    return 0;
} 
