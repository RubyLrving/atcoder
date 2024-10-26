#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main() {
    int n;
    cin >> n;

    vector<double> x(n);
    vector<double> y(n);

    rep(i, n) cin >> x[i] >> y[i];

    int res=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double m = (y[j] - y[i]) / (x[j] - x[i]);
            if(-1 <= m && m <= 1){
                res++;
            }
        }
    }
    cout << res << endl;

    return 0;
}