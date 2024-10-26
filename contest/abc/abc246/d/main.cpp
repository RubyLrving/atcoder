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

ll f(ll a, ll b){
    return a*a*a + a*a*b + b*b*a + b*b*b;
}

int main() {
    ll N, m=NUM_MAX;
    cin >> N;

    for(ll a=0; a <= 1000000; a++){
        ll ok = 1000000;
        ll ng = 0;

        while(abs(ok-ng)>0){
            ll mid = (ok + ng) / 2;
            if(f(a, mid) >= N){
                ok = mid;
            }else{
                ng = mid + 1;
            }
        }

        if(m > f(a, ok)) m = f(a, ok);
    }
    cout << m << endl;

    return 0;
} 