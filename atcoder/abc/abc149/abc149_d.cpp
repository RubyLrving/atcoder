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
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;

    vector<char> v(n);
    ll res = 0;
    for(int i=0; i<n; i++){
        if((i-k<0 && t[i] == 'r') || (i-k>=0 && t[i] == 'r' && v[i-k] != 'p')){ v[i] = 'p'; res += p; }
        else if((i-k<0 && t[i] == 's') || (i-k>=0 && t[i] == 's' && v[i-k] != 'r')){ v[i] = 'r'; res += r; }
        else if((i-k<0 && t[i] == 'p') || (i-k>=0 && t[i] == 'p' && v[i-k] != 's')){ v[i] = 's'; res += s; }
    }
    cout << res << endl;

    return 0;
}