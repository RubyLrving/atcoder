#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

void solve(int n, vector<ll> &A){
    vector<ll> dp(n+1, 0);

    rep(i, n){
        dp[i+1] = dp[i] + A[i];
    }
    reverse(A.begin(), A.end());
    reverse(dp.begin(), dp.end());

    ll res =0;
    rep(i, n){
        ll v = n - (i+1);
        ll sum = A[i] * v;
        res += sum - dp[i+1];
    }
    cout << res << endl;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;

    //n = 200000;
    vector<ll> A(n);
    //rep(i, n) A[i] = i+1;
    rep(i, n) cin >> A[i];
    sort(A.begin(), A.end());
    solve(n, A);

    return 0;
}