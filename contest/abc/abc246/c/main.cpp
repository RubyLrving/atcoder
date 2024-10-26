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
    ll N, K, X;
    cin >> N >> K >> X;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    rep(i, N){
        if(A[i]-X>=0){
            ll m = min(K, A[i]/X);
            A[i] = A[i] - (m*X);
            K = K - m;
            if(K==0) break;
        }
    }

    sort(A.begin(), A.end(), std::greater<ll>());
    rep(i, N){
        if(K==0) break;
        A[i] = 0;
        K--;
    }

    ll ans=0;
     for(auto a:A) ans += a;
     cout << ans << endl;

    return 0;
} 