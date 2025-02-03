#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int Q;
    cin >> Q;

    vector<pair<ll, ll>> A;
    ll idx = 0;
    ll d = 0;
    rep(i, Q){
        int q;
        cin >> q;

        if(q==1){
            int l;
            cin >> l;
            A.push_back({d, l});
            d += l;
        }

        if(q==2){
            idx++;
        }

        if(q==3){
            int k;
            cin >> k;
            k--;
            cout << A[idx + k].first - A[idx].first << endl;          
        }
    }

    return 0;
} 
