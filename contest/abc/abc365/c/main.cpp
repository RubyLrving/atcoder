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
    vector<ll> A(N);
    for(auto& a:A) cin >> a;
    sort(A.begin(), A.end());

    ll total = 0;
    rep(i, N) total += A[i];

    if(total <= M){
        cout << "infinite" << endl;
        return 0;
    }

    ll ok = 0;
    ll ng = M+1;
    while(abs(ok-ng)>1){
        ll mid = (ok + ng) / 2;
        ll sum = 0;
        rep(i, N) sum += min(mid, A[i]);

        if(sum <= M){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;

    return 0;
} 