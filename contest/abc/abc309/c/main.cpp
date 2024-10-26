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
using P = pair<ll,ll>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    ll N, K;
    cin >> N >> K;
    vector<P> A(N);

    ll max_k = 0;
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        A[i] = P(a, b);
        max_k += b;
    }

    sort(A.begin(), A.end(), [](P const& x, P const& y){
        return x.first < y.first;
    });

    ll ans=1;
    rep(i, N){
        if(max_k<=K){
            cout << ans << endl;
            return 0;
        }

        ans = A[i].first+1LL;
        max_k -= A[i].second;
    }

    cout << ans << endl;

    return 0;
} 