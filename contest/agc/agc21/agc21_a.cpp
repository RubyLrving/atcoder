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
    ll n;
    cin >> n;

    int res=0;
    if(10>n){ cout << n << endl; return 0; } 

    int is_9=0;
    while(n>0){
        if(n / 10 > 0){ res += 9; if(n%10<9) is_9=1; }
        else{
            if(n-1>=0 && is_9) res += n - 1;
            else res += n;
        }
        n = n / 10;
    }
    cout << res << endl;

    return 0;
}