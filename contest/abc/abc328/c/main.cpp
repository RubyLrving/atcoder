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
    string S;
    cin >> S;
    vector<int> l(Q), r(Q);
    rep(i, Q) cin >> l[i] >> r[i];

    vector<int> vt(N+1, 0);
    rep(i, N){
        if(S[i] == S[i+1]) vt[i+1] = vt[i] + 1;
        else vt[i+1] = vt[i];
    }

    rep(i, Q){
        cout << vt[r[i]-1] - vt[l[i]-1] << endl;
    }

    return 0;
} 