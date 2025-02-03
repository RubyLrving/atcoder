#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int max_x = 0;
    int max_y = 0;
    int min_x = w;
    int min_y = h;

    rep(i, h) rep(j, w){
        if(s[i][j] == '#'){
            max_x = max(max_x, j);
            max_y = max(max_y, i);
            min_x = min(min_x, j);
            min_y = min(min_y, i);
        }
    }

    rep(i, h) rep(j, w){
        if(min_x <= j && j <= max_x && min_y <= i && i <= max_y){
            if(s[i][j] == '.'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
} 
