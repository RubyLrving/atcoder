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

int A[50][50];

int main() {
    int H, W;
    cin >> H >> W;

    rep(i, H) rep(j, W) cin >> A[i][j];

    int sum=0;
    int cnt=0;
    for(int i1=0; i1<H; i1++){
        for(int i2=i1+1; i2<H; i2++){
            for(int j1=0; j1<W; j1++){
                for(int j2=j1+1; j2<W; j2++){
                    if(A[i1][j1] + A[i2][j2] <= A[i2][j1] + A[i1][j2]) sum++;
                    cnt++;
                }
            }
        }
    }

    if(cnt == sum) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}