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
    int R, C;
    cin >> R >> C;
    vector<string> B(R);
    vector<tuple<int, int, int>> bom;
    rep(i, R){
        cin >> B[i];
        rep(j, C){
            if(B[i][j] != '.' && B[i][j] != '#'){
                bom.push_back({B[i][j] - '0', i, j});
            }
        }
    }

    rep(i, R){
        rep(j, C){
            rep(k, bom.size()){
                int b = get<0>(bom[k]);
                int r = get<1>(bom[k]);
                int c = get<2>(bom[k]);
                int l = abs(i - r) + abs(j - c);
                if(b >= l) B[i][j] = '.';
            }
        }
    }
    rep(i, R) cout << B[i] << endl;

    return 0;
} 