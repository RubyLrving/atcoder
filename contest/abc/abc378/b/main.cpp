#include <bits/stdc++.h>
#include <atcoder/all>
 
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
    cin >> N;
    vector<int> q(N), r(N);
    rep(i, N) cin >> q[i] >> r[i];
    cin >> Q;
    vector<int> t(Q), d(Q);
    rep(i, Q) cin >> t[i] >> d[i];

    rep(i, Q){
        int index = t[i] - 1;
        int a = d[i] % q[index];
        if(a <= r[index]){
            cout << d[i] - a + r[index] << endl;
        }else{
            cout << d[i] - a + q[index] + r[index] << endl;
        }
    }

    return 0;
} 