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

int main(int argc, const char * argv[]) {
    int n, m, t;
    cin >> n >> m >> t;

    vector<double> a(m);
    vector<double> b(m);

    double res=n;
    double now=0;
    bool is_0 = false;
    rep(i, m){
        cin >> a[i] >> b[i];

        res -= (a[i] - now);
        now = b[i];
        if(res <= 0){
            is_0 = true;
            break;
        }
        res += (b[i] - a[i]);
        if(res > n) res = n;
    }
    if(now<t && is_0==false){
        res -= (t - now);
        if(res <= 0){
            is_0 = true;
        }
    }

    if(is_0) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}