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

ll modPow(ll a, ll n, ll mod){
    ll res = 1;
    while(n>0){
        if(n&1) res = res * a % mod;
        a = a * a % mod;
        n = n>>1;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), S(N), AA(N+1);
    map<ll, ll> mp;
    rep(i, N){
        cin >> A[i];
        AA[i+1] = AA[i] + A[i];
        S[i] = to_string(A[i]).size();
        mp[S[i]]++;
    }
    ll total = 0;
    rep(i, N){
        mp[S[i]]--;
        if(mp[S[i]] == 0) mp.erase(S[i]);

        for(auto m:mp){
            ll t = A[i] * modPow(10, m.first, 1000000000000000000) * m.second;
            total += t;
        }
        total += AA[N] - AA[i+1];
        // total %= 998244353;
        // cout << total << endl;
    }
    cout << total % 998244353 << endl;

    return 0;
} 