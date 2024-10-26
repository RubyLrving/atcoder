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
    vector<ll> A(N), S(N+1), AA(N+1);
    rep(i, N) cin >> A[i];
    rep(i, N) AA[i+1] = AA[i] + A[i];
    ll total = 0;
    rep(i, M) total += A[i]*(i+1);
    ll res = total;
    repx(i, 1, N+1){
        if(i+M>N) break;
        total = total - (AA[M+i-1]-AA[i-1]) + A[M+i-1]*M;
        res = max(res, total);
    }
    cout << res << endl;
    return 0;
} 