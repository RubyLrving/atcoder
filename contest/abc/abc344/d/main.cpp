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
    string T;
    int N;
    cin >> T >> N;

    vector<vector<ll>> dp(101, vector<ll>(101, 1e9));
    for(int i=0; i<101; i++) for(int j=0; j<101; j++) dp[i][j] = 1e9;
    dp[0][0] = 0;

    rep(i, N){
        for(int j=0; j<101; j++) dp[i+1][j] = dp[i][j];
        int a;
        cin >> a;
        for(int j=0; j<a; j++){
            string s;
            cin >> s;
            for(int k=0; k+s.size()<=T.size(); k++){
                int ok=1;
                for(int l=0; l<s.size(); l++){
                    if(T[k+l] != s[l]){
                        ok=0;
                        break;
                    }
                }
                if(ok){
                    dp[i+1][k+s.size()] = min(dp[i+1][k+s.size()], dp[i][k]+1);
                }
            }
        }
    }
    if(dp[N][T.size()]>=1e9) dp[N][T.size()]=-1;
    cout << dp[N][T.size()] << endl;
    return 0;
} 