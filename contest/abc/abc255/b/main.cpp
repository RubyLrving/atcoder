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
    int N, K;
    cin >> N >> K;
    vector<int> A(N), X(N), Y(N);
    rep(i, K) cin >> A[i];
    rep(i, N) cin >> X[i] >> Y[i];

    vector<double> D(N, 1e9+7);
    rep(i, K){
        int index = A[i]-1;
        double x1 = X[index];
        double y1 = Y[index];
        rep(j, N){
            if(j==index){
                D[j] = 0;
                continue;
            }
            double x2 = X[j];
            double y2 = Y[j];
            double d = sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) );
            D[j] = min(d, D[j]);
        }
    }
    double ans=0;
    rep(i, N) ans = max(ans, D[i]);
    cout << fixed_setprecision(6) << ans << endl;

    return 0;
} 