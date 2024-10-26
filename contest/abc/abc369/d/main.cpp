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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<ll>> dp(N+1, vector<ll>(2, 0));
    dp[0][1] = -1 * 2e18;

    for(int i=0; i<N; i++){
        dp[i+1][0] = max(dp[i][0], dp[i][1] + A[i] * 2);
        dp[i+1][1] = max(dp[i][1], dp[i][0] + A[i]);
    }

    cout << max(dp[N][0], dp[N][1]) << endl;

    return 0;
} 