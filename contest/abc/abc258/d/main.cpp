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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    
    ll ans = 2e18;
    ll add = 0;
    ll min_b = 2e18;
    rep(i, N){
        ll sum = 0;
        ll xx = X;
        sum = A[i] + B[i] + add;
        xx -= i+1;
        min_b = min(min_b, B[i]);
        sum += min_b * xx;
        ans = min(ans, sum);
        add += A[i] + B[i];
    }
    cout << ans << endl;

    return 0;
} 