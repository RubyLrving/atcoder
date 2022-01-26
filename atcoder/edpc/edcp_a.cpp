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
 
int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    
    ll dp[100002];
    rep(i, N+2) dp[i] = INF;
    
    dp[0]=0;
    
    for(int i=0; i<N; i++){
        chmin(dp[i+1], dp[i] + abs(H[i] - H[i+1]));
        chmin(dp[i+2], dp[i] + abs(H[i] - H[i+2]));
    }
    
    cout << dp[N-1] << endl;
    
    return 0;
}