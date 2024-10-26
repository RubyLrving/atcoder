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

string s;
int q;

char g(char a, ll add){
    return char('A'+(a-'A'+add)%3);
}

char dfs(ll t, ll k){
    if(t==0) return s[k];
    if(k==0) return g(s[0], t);
    return g(dfs(t-1, k/2), k%2+1);
}

int main() {
    cin >> s >> q;
    rep(i, q){
        ll t, k;
        cin >> t >> k;
        cout << dfs(t, k-1) << endl;
    }

    return 0;
}