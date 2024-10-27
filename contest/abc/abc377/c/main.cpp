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
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> st;

    rep(i, M){
        ll a, b;
        cin >> a >> b;
        st.insert({a, b});
        for(auto j:{-1, 1}){
            for(auto k:{-2, 2}){
                st.insert({a+j, b+k});
                st.insert({a+k, b+j});
            }            
        }
    }
    ll ans = N * N;
    for(auto [x, y]:st){
        if(0<x && x<=N && 0<y && y<=N) ans--;
    }
    cout <<  ans << endl;

    return 0;
} 