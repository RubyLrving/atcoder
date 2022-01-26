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
 
ll dp[100002];
int H[100002];
 
int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N >> K;
 
    rep(i, N+2) dp[i] = INF;
    rep(i, N) cin >> H[i];
    
    dp[0] = 0;
    
    for(int i=0; i<N; i++){
        for(int j=1; j<=K; j++){
            chmin(dp[i+j], dp[i] + abs(H[i+j]-H[i]));
        }
    }
    
    cout << dp[N-1] << endl;
    
    return 0;
}