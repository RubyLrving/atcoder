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
    int A, B, M, mina=200010, minb=200010;
    cin >> A >> B >> M;

    vector<int> a(A), b(B);
    rep(i, A){ cin >> a[i]; mina = min(mina, a[i]);}
    rep(i, B){ cin >> b[i]; minb = min(minb, b[i]);}

    vector<int> x(M), y(M), c(M);
    rep(i, M) cin >> x[i] >> y[i] >> c[i];

    int res=200010;
    rep(i, M){
        res = min(res, a[x[i]-1] + b[y[i]-1] - c[i]);
    }

    cout << min(res, mina+minb) << endl;

    return 0;
}