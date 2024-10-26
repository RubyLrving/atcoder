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
    int N;
    double D, H;
    cin >> N >> D >> H;

    vector<double> d(N), h(N);
    rep(i, N) cin >> d[i] >> h[i];

    double M = H / D;
    for(int i=0; i<N; i++){
        if(d[i] <= D){
            double m = (H - h[i]) / (D - d[i]);
            if(M >= m) M = min(M, m);
        }
    }

    double res = H - (M * D);
    cout << fixed_setprecision(4) << res << endl;

    return 0;
}