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
    int N, Q;
    cin >> N >> Q;
    vector<char> H(Q);
    vector<int> T(Q);
    rep(i, Q) cin >> H[i] >> T[i], T[i]--;

    int ans = 0;
    int L = 0, R = 1;
    rep(i, Q){
        auto dist = [&](int from, int to, const int ng){
            if(from > to) swap(from, to);
            if(from < ng && ng < to) return N - to + from;
            return to - from;
        };

        if(H[i] == 'L'){
            ans += dist(L, T[i], R);
            L = T[i];
        }else{
            ans += dist(R, T[i], L);
            R = T[i];
        }
    }
    cout << ans << endl;

    return 0;
} 