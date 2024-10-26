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
    int N;
    cin >> N;
    vector<ll> X(N), P(N);
    rep(i, N) cin >> X[i];
    rep(i, N) cin >> P[i];
    int Q;
    cin >> Q;
    vector<ll> L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];
    vector<ll> PP(N+1);
    rep(i, N) PP[i+1] = PP[i] + P[i];

    rep(i, Q){
        int l = lower_bound(X.begin(), X.end(), L[i]) - X.begin();
        int r = upper_bound(X.begin(), X.end(), R[i]) - X.begin();

        cout << PP[r] - PP[l] << endl;
    }

    return 0;
} 