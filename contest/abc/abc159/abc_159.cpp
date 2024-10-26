#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;

    vector<ll> v(n);
    map<ll, ll> m;
    rep(i, n){
        cin >> v[i];
        m[v[i]]++;
    }

    ll res = 0;
    for(map<ll, ll>::iterator itr = m.begin(); itr != m.end(); itr++){
        res += itr->second * (itr->second - 1) / 2;
    }
    for(int i=0; i<n; i++){
        ll sum = m[v[i]];
        ll v1 = ((sum-1) * (sum-2) / 2);
        ll v2 = (sum * (sum - 1) / 2);
        cout << res + v1 - v2 << endl;
    }

    return 0;
}