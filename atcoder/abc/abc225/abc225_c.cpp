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

void solve(ll n, ll m, vector<vector<ll>> B){
    ll x = (B[0][0]-1) % 7;
    ll y = (B[0][0]-1) / 7;
    rep(i, n) rep(j, m){
        int v = (y+i)*7+x+j + 1;
        if(B[i][j] != v || x+j >= 7){
            cout << "No" << endl;
            return;
        }
    } 
    cout << "Yes" << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> B(n);
    rep(i, n){
        B[i].resize(m);
        rep(j, m){
            cin >> B[i][j];
        }
    } 

    solve(n, m, B);

    return 0;
}