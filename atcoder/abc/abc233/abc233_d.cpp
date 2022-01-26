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
 
int main() {
    ll N, K;
    cin >> N >> K;
 
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> B(N+1);
    rep(i, N) B[i+1] = A[i] + B[i];
 
    ll res=0;
    map<ll, ll> mp;
    for(int r=1; r<N+1; r++){
        mp[B[r-1]]++;
        res += mp[B[r]-K];
    }
    cout << res << endl;
 
    return 0;
}