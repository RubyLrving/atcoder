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
    ll N, X;
    cin >> N;

    queue<ll> A;
    ll total=0;
    rep(i, N){
        ll a;
        cin >> a;
        A.push(a);
        total+=a;
    }

    cin >> X;
    ll sum=(X/total)*total;
    ll res=(X/total)*A.size();
    while(sum<=X){
        ll a = A.front();
        A.pop();

        sum += a;
        res++;
        A.push(a);
    }
    cout << res << endl;

    return 0;
}