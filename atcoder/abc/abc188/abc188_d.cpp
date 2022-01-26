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
const long long INF = 1LL << 60;

int main() {
    ll N, C;
    cin >> N >> C;
    vector<pair<ll, ll>> event;
    for(ll i = 0; i < N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        event.emplace_back(a - 1, c);
        event.emplace_back(b, -c);
    }
    sort(event.begin(), event.end());

    ll ans = 0, fee = 0, t = 0;
    for(int i=0; i<event.size(); i++){
        auto x = event[i].first;
        auto y = event[i].second;
        
        if(x != t){
            ans += min(C, fee) * (x - t);
            t = x;
        }
        fee += y;
    }
    cout << ans << endl;
    return 0;
}