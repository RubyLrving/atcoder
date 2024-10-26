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
    string s;
    cin >> s;

    int q;
    cin >> q;

    int cmd, f, is_reverse=0;
    string c;
    rep(i, q){
        cin >> cmd;
        if(cmd==1){
            is_reverse = 1 - is_reverse;
        }else{
            cin >> f >> c;
            if(is_reverse) f = 3 - f;
            if(f==1) s.insert(0, c);
            else s.insert(s.length(), c);            
        }
    }
    if(is_reverse) reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}