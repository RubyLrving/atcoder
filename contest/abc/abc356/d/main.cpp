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
    ll N, M;
    cin >> N >> M;
    ll MOD = 998244353;
    ll total_sum = 0;

    for(ll bit = 0; bit < 60; bit++){
        if(M & (1 << bit)){
            ll full_cycles = (N + 1) / (1 << (bit + 1));
            ll remainder = (N + 1) % (1 << (bit + 1));

            ll count_1s = full_cycles * (1 << bit) + max(0LL, remainder - (1 << bit));
            total_sum += count_1s;
            total_sum %= MOD;
        }
    }
    cout << total_sum << endl;

    return 0;
} 