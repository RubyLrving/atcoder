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
    int t;
    cin >> t;

    vector<ll> L(t), R(t);
    
    rep(i, t){
        cin >> L[i] >> R[i];
        ll a = L[i]+L[i];
        ll l = R[i];
        ll n = R[i]-L[i]-L[i]+1;
        if(l>=a){
            ll p = n*(a+l) / 2;
            ll q = (L[i]+L[i])*n;
            ll res = p - q + n;
            cout << res << endl;
        }else{
            cout << 0 << endl;
        }
    }
 
    return 0;
}