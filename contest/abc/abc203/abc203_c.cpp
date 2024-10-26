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
    ll N, K;
    cin >> N >> K;

    vector<pair<ll,ll>> P(N);
    rep(i, N) cin >> P[i].first >> P[i].second;

    sort(P.begin(), P.end());

    ll res=0, cnt=0;
    for(ll i=0; i<N; i++){

        if(P[i].first-cnt<=K){
            K -= P[i].first - cnt;
            res += P[i].first - cnt;
            K += P[i].second;
        }else{
            res += K;
            K=0;
            break;
        }
        cnt = P[i].first;
    }
    cout << res + K << endl;

    return 0;
}