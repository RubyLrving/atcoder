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
    int n, m;
    cin >> n >> m;

    n = n % 12;
    m = m % 60;

    double l = 360 / 60 * (double)m;
    double r = 360.0 / 12.0 / 60.0 * (double)m + 360 / 12 * (double)n;
    double res = (abs(r - l) < 180)? abs(r - l):360 - abs(r - l);
    cout << fixed_setprecision(10) << res << endl;

    return 0;
}