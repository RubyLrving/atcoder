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
    ll N, K;
    cin >> N >> K;

    vector<tuple<ll, ll, ll>> A(N);
    rep(i, N){
        ll a;
        cin >> a;
        A[i] = make_tuple(i, a, 0);
    }

    sort(A.begin(), A.end(), []( const auto &x, const auto &y )
    {
        return get<1>( x ) < get<1>( y );
    });

    ll add = K / N;
    ll amari = K % N;
    for(int i=0; i<N; i++){
        if(i<amari) get<2>(A[i]) = add + 1;
        else get<2>(A[i]) = add;
    }

    sort(A.begin(), A.end(), []( const auto &x, const auto &y )
    {
        return get<0>( x ) < get<0>( y );
    });

    for(int i=0; i<N; i++){
        cout << get<2>(A[i]) << endl;
    }

    return 0;
}