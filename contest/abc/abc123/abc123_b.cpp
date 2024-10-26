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
    vector<int> V(5);
    rep(i, 5) cin >> V[i];

    sort(V.begin(), V.end(), [](const auto lhf, const auto rhf){
        return lhf % 10 < rhf % 10;
    });

    int ok=0, t=0;
    rep(i, 5){
        if(V[i]%10>0 && ok==0){
            ok=1;
            t+=V[i];
        }else{
            if(V[i]%10>0) t+=(10-V[i]%10) + V[i];
            else t+=V[i];
        }
    }
    cout << t << endl;

    return 0;
}