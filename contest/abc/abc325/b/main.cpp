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
    vector<ll> W(N), X(N);
    rep(i, N) cin >> W[i] >> X[i];

    ll ans = 0;
    rep(t, 24){
        ll sum_w = 0;
        rep(i, N){
            ll meet_start = (t + X[i]) % 24;
            
            if(9<meet_start && meet_start<=18){
                sum_w += W[i];
            }
        }
        ans = max(ans, sum_w);
    }
    cout << ans << endl;

    return 0;
} 