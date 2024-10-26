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
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b(Q), k(Q);
    rep(i, Q) cin >> b[i] >> k[i];

    rep(i, Q){
        int ng = -1;
        int ok = 2e8;
        while(abs(ok-ng)>1){
            int mid = (ok + ng) / 2;
            int l = lower_bound(a.begin(), a.end(), b[i] - mid) - a.begin();
            int r = upper_bound(a.begin(), a.end(), b[i] + mid) - a.begin();
            if(r-l >= k[i]){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        cout << ok << endl;
    }

    return 0;
} 