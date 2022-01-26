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

double dp[102][64][64][64];
int main(int argc, const char * argv[]) {
    int n;
    ll d;
    cin >> n >> d;

    int cnt_2 = 0, cnt_3 = 0, cnt_5 = 0;
    while (d % 2 == 0) {
        d /= 2;
        cnt_2++;
    }
    while (d % 3 == 0) {
        d /= 3;
        cnt_3++;
    }
    while (d % 5 == 0) {
        d /= 5;
        cnt_5++;
    }
    if(d != 1){ cout << 0 << endl; return 0; }

    dp[0][0][0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=cnt_2; j++){
            for(int k=0; k<=cnt_3; k++){
                for(int l=0; l<=cnt_5; l++){
                    int j1 = min(j + 1, cnt_2);
                    int j2 = min(j + 2, cnt_2);
                    int k1 = min(k + 1, cnt_3);
                    int l1 = min(l + 1, cnt_5);
                    dp[i+1][j ][k ][l ] += dp[i][j][k][l] / 6;
                    dp[i+1][j1][k ][l ] += dp[i][j][k][l] / 6;
                    dp[i+1][j ][k1][l ] += dp[i][j][k][l] / 6;
                    dp[i+1][j2][k ][l ] += dp[i][j][k][l] / 6;
                    dp[i+1][j ][k ][l1] += dp[i][j][k][l] / 6;
                    dp[i+1][j1][k1][l ] += dp[i][j][k][l] / 6;
                }
            }
        }
    }
    cout << fixed_setprecision(9) << dp[n][cnt_2][cnt_3][cnt_5] << endl;
    return 0;
}