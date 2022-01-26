#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9
 
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
 
int main() {
    ll N, M, Q;
    cin >> N >> M >> Q;
 
    vector<P> W(N);
    rep(i, N) cin >> W[i].first >> W[i].second;
 
    sort(W.begin(), W.end(), []( const auto &x, const auto &y )
    {
        return get<1>( x ) == get<1>( y ) ? get<0>( x ) > get<0>( y ) : get<1>( x ) > get<1>( y );
    });
 
    vector<ll> X(M);
    rep(i, M) cin >> X[i];
    
 
    rep(i, Q){
        int L, R;
        cin >> L >> R;
        L = L - 1;
        R = R - 1;
 
        ll res = 0;
        vector<P> temp_W(W.size());
        copy(W.begin(), W.end(), temp_W.begin());

        vector<ll> temp_X(X.size());
        copy(X.begin(), X.end(), temp_X.begin());
        temp_X.erase(temp_X.begin() + L, temp_X.begin() + R + 1);
        sort(temp_X.begin(), temp_X.end());

        for(int j=0; j<temp_X.size(); j++){
            for(int k=0; k<temp_W.size(); k++){
                if(temp_X[j]>=temp_W[k].first){
                    res += temp_W[k].second;
                    temp_W.erase(temp_W.begin() + k);
                    break;
                }
            }   
        }
        cout << res << endl;
    }
 
    return 0;
}