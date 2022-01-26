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
    cin >> N;

    vector<ll> x(N);
    vector<ll> y(N);
    rep(i, N) cin >> x[i] >> y[i];

    int res=0;
    for(int p=0; p<N; p++){
        for(int q=p+1; q<N; q++){
            for(int r=q+1; r<N; r++){
                ll x1 = x[q] - x[p]; 
                ll x2 = x[r] - x[p]; 
                ll y1 = y[q] - y[p]; 
                ll y2 = y[r] - y[p];

                long double ans = abs((long double)(x1 * y2) - (long double)(x2 * y1)) * 0.5;
                if(ans>0) res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}

//12|x1y2−x2y1|