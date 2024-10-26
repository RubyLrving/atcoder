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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N), AA(N+1);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());
    rep(i, N) AA[i+1] = AA[i] + A[i];

    rep(i, Q){
        int x;
        cin >> x;

        auto l = lower_bound(A.begin(), A.end(), x);
        auto r = upper_bound(A.begin(), A.end(), x);

        ll res = 0;
        if(l != A.end()) res += x * (l - A.begin()) - AA[l - A.begin()] - AA[0];
        else res += x * N - AA[N] - AA[0];

        if(r != A.end()) res += AA[N] - AA[r - A.begin()] - x * (A.end() - r);

        cout << res << endl;    
    }

    return 0;
} 