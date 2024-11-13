#include <bits/stdc++.h>
#include <atcoder/all>
 
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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> XA(M);
    for(auto& [x, a]:XA) cin >> x;
    for(auto& [x, a]:XA) cin >> a;
    XA.push_back({N+1, 1});
    sort(XA.begin(), XA.end());

    ll cnt = 0;
    ll ans = 0;
    for(int i=0; i<M; i++){
        auto& [x1, a1] = XA[i];
        auto& [x2, a2] = XA[i+1];

        cnt += a1;
        ll d = x2 - x1;
        ans += d * (d - 1) / 2LL;
        ans += (cnt - d) * d;
        cnt -= d;

        if(cnt < 0){
            cout << -1 << endl;
            return 0;
        }
    }

    if(cnt != 0) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
} 