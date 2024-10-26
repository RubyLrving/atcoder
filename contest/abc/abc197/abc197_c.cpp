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

ll N;
ll A[20];

ll dfs(int n, ll orred, ll xorred){

    if(n == N) return xorred ^ orred;

    return min(dfs(n+1, orred | A[n], xorred), dfs(n+1, A[n], xorred ^ orred));
}

int main() {
    
    cin >> N;
    rep(i, N) cin >> A[i]; 

    ll res = dfs(0, 0, 0);

    cout << res << endl;

    return 0;
}