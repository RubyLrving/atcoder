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
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if((N==0)||(M==0)){
        cout<<-1<<endl;
        return 0;
	}

    ll ans=-1;
    rep(i, N){
        ll ok=0;
        ll ng=M;
        while (ng - ok>-1)
        {
            ll mid = (ok+ng) / 2;
            if(abs(A[i] - B[mid]) <= D){
                ans = max(ans, A[i] + B[mid]);   
            }
            if(A[i]+D < B[mid]) ng = mid-1;
            else ok = mid+1;
        }
    }
    cout << ans << endl;

    return 0;
} 