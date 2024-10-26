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

ll N, M, K;
vector<vector<ll>> bridge;

ll dfs(ll pos, ll k, ll sum){

    if(k==K+1 && pos==0){
        cout << sum << endl;
        return sum;
    }else if(k==K+1 && pos!=0) return 0;

    ll res=0;
    rep(i, N){
        if(i==pos) continue;
        int ok=0;
        for(auto b:bridge[pos]){
            if(b == i){
                ok=1;
                break;
            }
        }
        if(ok) continue;

        res += dfs(i, k+1, sum + N-bridge[pos].size()-1) % 998244353;
    }
    

    return res;
}

int main() {
    
    cin >> N >> M >> K;
    bridge.resize(N);
    
    rep(i, M){
        int a, b;
        cin >> a >> b;
        bridge[a-1].push_back(b-1);
        bridge[b-1].push_back(a-1);
    }

    ll res = dfs(0, 0, 0);

    cout << res << endl;

    return 0;
}