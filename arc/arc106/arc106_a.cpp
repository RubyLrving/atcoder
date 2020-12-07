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
    ll N;
    cin >> N;
    int x_max=0;
    int y_max=0;
    for(x_max=0; pow(3, x_max)<=N; x_max++){}
    for(y_max=0; pow(5, y_max)<=N; y_max++){}

    bool res=false;
    ll res_x=0, res_y=0;;
    for(int x=1; x<=x_max; x++){
        for(int y=1; y<=y_max; y++){
            if(powl(3, x) + powl(5, y) == N) { res=true; res_x = x; res_y = y; break; }
        }
    }

    if(res) cout << res_x << ' ' << res_y << endl;
    else cout << "-1" << endl;

    return 0;
}