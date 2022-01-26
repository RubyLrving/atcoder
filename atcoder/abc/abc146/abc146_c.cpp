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

ll d(ll a) {
    ll res = 0;
    while (a) {
        ++res;
        a /= 10;
    }
    return res;
}

int main() {
    ll A, B, X;
    cin >> A >> B >> X;

    ll left = 0, right = 1000000001;
    while(right-left>1){
        ll mid = (left + right) / 2;
        if(A*mid + B*d(mid)>X){
            right=mid;
        }else{
            left=mid;
        }
    }
    cout << left << endl;

    return 0;
}