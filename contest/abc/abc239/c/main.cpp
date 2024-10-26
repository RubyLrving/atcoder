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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int ok=0;
    for(ll i=-3; i<4; i++){
        for(ll j=-3; j<4; j++){
            ll a = pow(x1 - (x1 - i), 2) + pow(y1-(y1 - j), 2);
            ll b = pow(x2 - (x1 - i), 2) + pow(y2-(y1 - j), 2);
            ll c = pow(x1 - (x2 - i), 2) + pow(y1-(y2 - j), 2);
            ll d = pow(x2 - (x2 - i), 2) + pow(y2-(y2 - j), 2);

            if((a == 5 && b == 5) || (c == 5 && d == 5)){
                ok=1;
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 