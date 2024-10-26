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

ll N;
ll A[11][11];
ll ANS=0;

void dfs(ll i, ll j, ll x, ll y, ll cnt, ll sum){

    if(cnt>=N){
        ANS = max(ANS, sum);
        return;
    }

    ll p=1;
    rep(i, N-cnt-1) p*=10;

    sum += A[i][j] * p;
    i += x;
    j += y;

    if(i<0) i = N-1;
    if(i>=N) i = 0;
    if(j<0) j = N-1;
    if(j>=N) j = 0;

    dfs(i, j, x, y, cnt+1, sum);
}

int main() {

    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    rep(i, N){
        rep(j, S.size()){
            A[i][j] = S[i][j] - '0';
        }      
    }


    rep(i, N){
        rep(j, N){
            dfs(i, j, -1, -1, 0, 0);
            dfs(i, j, 0, -1, 0, 0);
            dfs(i, j, 1, -1, 0, 0);
            dfs(i, j, -1, 0, 0, 0);
            dfs(i, j, 1, 0, 0, 0);
            dfs(i, j, -1, 1, 0, 0);
            dfs(i, j, 0, 1, 0, 0);
            dfs(i, j, 1, 1, 0, 0);
        }
    }

    cout << ANS << endl;

    return 0;
} 