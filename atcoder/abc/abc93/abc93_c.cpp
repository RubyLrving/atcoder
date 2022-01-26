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
    vector<int> V(3);
    rep(i, 3) cin >> V[i];

    int odd=0, even=0;
    rep(i, 3){
        if(V[i]%2==1) odd++;
        else even++;
    }

    int res=0;
    if(odd==2){
        res++;
        rep(i, 3) if(V[i]%2==1) V[i]++;
    }
    if(even==2){
        res++;
        rep(i, 3) if(V[i]%2==0) V[i]++;
    }

    int ma = max(max(V[0], V[1]), V[2]);
    rep(i, 3) res += (ma-V[i]) / 2;
    cout << res << endl;

    return 0;
}