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

char hw[103][103];

int main() {
    int h, w;
    cin >> h >> w;

    rep(i, w+2) hw[0][i] = '#';
    rep(i, w+2) hw[h+1][i] = '#';
    rep(i, h+2) hw[i][0] = '#';
    rep(i, h+2) hw[i][w+1] = '#';

    rep(i, h){
        string s;
        cin >> s;

        rep(j, w){
            hw[i+1][j+1] = s[j];
        }
    }

    rep(i, h+2){
        rep(j, w+2){
            cout << hw[i][j];
        }
        cout << endl;
    }

    return 0;
}