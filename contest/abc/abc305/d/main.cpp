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
    map<ll, tuple<ll, ll>> mp;
    ll total = 0;
    for(int i=2; i<N; i+=2){
        total += A[i] - A[i-1];
        mp[A[i]] = make_tuple(A[i-1], total);
    }
    
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll l, r;
        cin >> l >> r;
        auto l_itr = mp.lower_bound(l);
        auto r_itr = mp.lower_bound(r);

        ll ans = 0;

        if(get<0>(r_itr->second) < r){
            ans = get<1>(r_itr->second) - (r_itr->first - r);
        }else{
            ans = get<1>(r_itr->second) - (r_itr->first - get<0>(r_itr->second));
        }

        if(get<0>(l_itr->second) < l){
            ans = ans - get<1>(l_itr->second) + (l_itr->first - l);
        }else{
            ans = ans - get<1>(l_itr->second) + (l_itr->first - get<0>(l_itr->second));
        }

        cout << max(ans, 0LL) << endl;
    }

    return 0;
} 