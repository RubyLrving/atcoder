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
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;

    vector<tuple<ll, ll, ll>> vec;
    vec.push_back(tuple<ll, ll, ll>(Q*8, 1, Q));
    vec.push_back(tuple<ll, ll, ll>(H*4, 2, H));
    vec.push_back(tuple<ll, ll, ll>(S*2, 4, S));
    vec.push_back(tuple<ll, ll, ll>(D, 8, D));

    sort(vec.begin(), vec.end());

    ll cnt=0, res=0;
    N = N * 4;
    while(N>1){
        if(N % get<1>(vec[cnt]) == 0){
            res += N / get<1>(vec[cnt]) * get<2>(vec[cnt]);
            break;
        }else{
            res += N / get<1>(vec[cnt]) * get<2>(vec[cnt]);
            N = N % get<1>(vec[cnt]);
            cnt++;
        }
    }
    cout << res << endl;

    return 0;
}