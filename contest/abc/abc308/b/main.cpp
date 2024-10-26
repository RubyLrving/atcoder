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
    int N, M;
    cin >> N >> M;
    vector<string> C(N), D(M);
    rep(i, N) cin >> C[i];
    rep(i, M) cin >> D[i];
    map<string, int> mp;
    rep(i, M+1){
        int p;
        cin >> p;
        if(i==0) mp[""] = p;
        else mp[D[i-1]] = p;
    }

    int ans = 0;
    rep(i, N){
        if(mp.find(C[i]) != mp.end()){
            ans += mp[C[i]];
        }else{
            ans += mp[""];
        }
    }
    cout << ans << endl;

    return 0;
} 