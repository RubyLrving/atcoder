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
    ll N, T;
    cin >> N >> T;
    vector<ll> A(T), B(T);
    rep(i, T) cin >> A[i] >> B[i];

    map<ll, ll> mp;
    mp[0] = N;
    vector<ll> P(N);
    rep(i, T){
        ll p = P[A[i]-1];
        P[A[i]-1] += B[i];
        mp[p] -= 1;
        if(mp[p]==0) mp.erase(p);
        mp[p+B[i]] += 1;
        cout << mp.size() << endl;
    }

    return 0;
} 