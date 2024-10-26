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
    int H, W, si, sj;
    cin >> H >> W;
    cin >> si >> sj;

    si--;
    sj--;

    vector<string> HW(H);
    for(int i=0; i<H; i++){
        cin >> HW[i];
    }
    string X;
    cin >> X;
    for(int i=0; i<X.size(); i++){
        int ni = si;
        int nj = sj;
        if(X[i] == 'L') nj--;
        if(X[i] == 'R') nj++;
        if(X[i] == 'U') ni--;
        if(X[i] == 'D') ni++;

        if(0 <= nj && nj < W && 0 <= ni && ni < H && HW[ni][nj] == '.'){
            si = ni;
            sj = nj;
        }
    }
    cout << si+1 << ' ' << sj+1 << endl;

    return 0;
} 