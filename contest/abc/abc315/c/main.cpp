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
    int N;
    cin >> N;
    vector<pair<ll, ll>> v(N);
    rep(i, N){
        ll f, s;
        cin >> f >> s;
        v[i] = P(s, f);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll s = v[1].first;
    ll k = v[1].second;
    if(k == v[0].second) s /= 2;

    repx(i, 2, N){
        if(k == v[i].second){
            s = max(s, v[i].first / 2);
        }else{
            s = max(s, v[i].first);
        }
    }
    cout << v[0].first + s << endl;

    return 0;
} 