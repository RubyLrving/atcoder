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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> odd, even;
    rep(i, N){
        if(A[i]%2==0) odd.push_back(A[i]);
        else even.push_back(A[i]);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    ll ans=-1;
    if(odd.size()>1) ans = odd[odd.size()-1] + odd[odd.size()-2];
    if(even.size()>1) ans = max(ans, even[even.size()-1] + even[even.size()-2]);
    cout << ans << endl;
    return 0;
} 