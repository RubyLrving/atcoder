#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cctype>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9
 
using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;
 
ll dp[100002][3];
ll A[100002][3];
 
 
 
int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
 
    rep(i, N) cin >> A[i][0] >> A[i][1] >> A[i][2];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(j==k) continue;
                chmax(dp[i+1][k], dp[i][j] + A[i][k]);
            }
        }
    }
    
    ll res=0;
    rep(i, 3) res = max(res, dp[N][i]);
    cout << res << endl;
    
    return 0;
}
