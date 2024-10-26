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
    int N, M;
    cin >> N >> M;

    vector<P> v(N+M);
    rep(i, N){
        int a;
        cin >> a;
        v[i].first = a;
        v[i].second = 0;
    }
    rep(i, M){
        int b;
        cin >> b;
        v[i+N].first = b;
        v[i+N].second = 1;
    }

    sort(v.begin(), v.end(), [](const auto &x, const auto &y ){
        return get<0>( x ) == get<0>( y ) ? get<1>( x ) < get<1>( y ) : get<0>( x ) < get<0>( y );
    });

    int res=1000000007;
    rep(i, v.size()-1){
        if(v[i].second != v[i+1].second){
            int s = abs(v[i].first - v[i+1].first);
            res = min(res, s);
        }
    }
    cout << res << endl;

    return 0;
}