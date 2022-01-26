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

int main() {
    int n;
    int red=0, blue=0;
    cin >> n;

    rep(i, n){
        string s;
        cin >> s;
        rep(j, n){
            if(s[j] == 'R') red++;
            else if(s[j] == 'B') blue++;
        }
    }

    if(red==blue) cout << "DRAW" << endl;
    else if(red>blue) cout << "TAKAHASHI" << endl;
    else cout << "AOKI" << endl;

    return 0;
}