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
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    vector<int> v(3);
    v[0] = pow(x1 - x2, 2) + pow(y1 - y2, 2);
    v[1] = pow(x2 - x3, 2) + pow(y2 - y3, 2);
    v[2] = pow(x3 - x1, 2) + pow(y3 - y1, 2);

    sort(v.begin(), v.end());

    if(v[0] + v[1] == v[2]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 