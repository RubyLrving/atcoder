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
    string s;
    cin >> s;

    if(s[0] == '1'){
        cout << "No" << endl;
        return 0;
    }

    if( (s[6] == '1' && s[3] == '0') ||
        (s[3] == '1' && s[1] == '0' && s[7] == '0') ||
        (s[9] == '1' && s[5] == '0') ||
        (s[5] == '1' && s[2] == '0' && s[8] == '0') ||
        ((s[1] == '1' || s[7] == '1') && s[4] == '0') ||
        ((s[2] == '1' || s[8] == '1') && s[4] == '0')
    ){
        cout << "Yes" << endl;       
        return 0;
    }
    cout << "No" << endl;

    return 0;
} 