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
    ll N;
    cin >> N;

    if(N==1){
        cout << 0 << endl;
        return 0;
    }
    N--;

    for(ll keta=1; ; keta++){
        ll l = (keta - 1) / 2;
        ll num = 9;
        rep(i, l) num *= 10;
        if(N > num){
            N -= num;
            continue;
        }

        num = 1;
        rep(i, (keta - 1) / 2) num *= 10;
        N += num - 1;
        string s = to_string(N);
        string rs = s;
        reverse(rs.begin(), rs.end());
        if(keta&1) s.pop_back();
        cout << s << rs << endl;
        break;
    }

    return 0;
} 