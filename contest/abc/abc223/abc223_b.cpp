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
    string s;
    cin >> s;

    string l = s;
    string r = s;
    string res_min = s;
    string res_max = s;
    int n = s.size();

    rep(i, n){
        res_min = min(res_min, l);
        res_max = max(res_max, l);
        l = l + l[0];
        l.erase(0, 1);

        res_min = min(res_min, r);
        res_max = max(res_max, r);
        r = r[n-1] + r;
        r.erase(n, 1);       
    }

    cout << res_min << endl;
    cout << res_max << endl;

    return 0;
}