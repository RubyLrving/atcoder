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
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    string s;
    cin >> s;

    string t = s.substr(l, r-l+1);
    reverse(t.begin(), t.end());

    int cnt=0;
    for(int i=l; i<=r; i++){
        s[i] = t[cnt];
        cnt++;
    } 
    cout << s << endl;

    return 0;
}