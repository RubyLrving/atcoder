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
    int H, W;
    cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W, '.'));

    rep(i, H){
        string s;
        cin >> s;
        rep(j, W){
            C[i][j] = s[j];
        }
    }

    vector<int> res(W);
    rep(i, W){
        int sum = 0;
        rep(j, H){
            if(C[j][i] == '#') sum++;
        }
        res[i] = sum;
    }

    rep(i, W){
        cout << res[i];
        if(i < W-1) cout << ' ';
    }
    cout << endl;

    return 0;
} 