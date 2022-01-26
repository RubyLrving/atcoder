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

    int ok = 1;
    if(s[0] != 'A') ok = 0;
    if(s[1]-'0' < 49 || 74 < s[1]-'0') ok = 0;
    if(s[s.size()-1]-'0' < 49 || 74 < s[s.size()-1]-'0') ok = 0;

    int sum=0, csum=0;
    repx(i, 2, s.size()-1){
        int n = s[i] - '0';
        if(49<=n && n<=74) sum++;
        if(n==19) csum++;
    }

    if(ok && csum == 1 && sum == s.size() - 4) cout << "AC" << endl;
    else cout << "WA" << endl;

    return 0;
}