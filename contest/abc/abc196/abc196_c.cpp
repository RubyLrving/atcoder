#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using P = pair<int,int>;

#define rep(i,n) for(ll i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9
 
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    ll N;
    cin >> N;

    ll cnt=0;
    while(stoll((to_string(cnt) + to_string(cnt))) <= N){
        cnt++;
    }
    cout << cnt-1 << endl;

    return 0;
}