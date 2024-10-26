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
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<int>> total(N+1, vector<int>(26, 0));
    rep(i, N) total[i+1][S[i] - 'A']++;
    rep(i, N){
        rep(j, 26) total[i+1][j] = total[i+1][j] + total[i][j];
    }

    ll ans = 0;
    repx(i, 1, N){
        rep(j, 26){
            ll l = total[i][j] - total[0][j];
            ll r = total[N][j] - total[i][j];
            if(S[i] - 'A' == j) r--;
            ans += l * r;
        }
    }
    cout << ans << endl;
    
    return 0;
}