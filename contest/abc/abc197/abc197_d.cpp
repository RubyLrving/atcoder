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
    double N, x0, y0, xn, yn;
    cin >> N;
    cin >> x0 >> y0;
    cin >> xn >> yn;

    double px = (xn + x0) / 2.0;
    double py = (yn + y0) / 2.0;
    double degree = 360.0 / N;
    double radian = degree * pai / 180.0;
    double x = x0 - px;
    double y = y0 - py;
    double x1 = x * cos(radian) - y * sin(radian);
    double y1 = x * sin(radian) + y * cos(radian);

    cout << fixed_setprecision(5) << x1 + px << " " << y1 + py << endl;

    return 0;
}