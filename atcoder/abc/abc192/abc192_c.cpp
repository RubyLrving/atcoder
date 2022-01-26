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
const long long INF = 1LL << 60;

ll g2(ll x){
    vector<int> temp;
    while(x>0){
        int r = x % 10;
        x = x / 10;
        temp.push_back(r);
    }

    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());

    ll ret=0;
    for(int i=0; i<temp.size(); i++){
        ret += temp[i] * pow(10, i);
    }
    return ret;
}

ll g1(ll x){
    vector<int> temp;
    while(x>0){
        int r = x % 10;
        x = x / 10;
        temp.push_back(r);
    }

    sort(temp.begin(), temp.end());

    ll ret=0;
    for(int i=0; i<temp.size(); i++){
        ret += temp[i] * pow(10, i);
    }
    return ret;
}

ll dfs(ll x){
    ll ret = g1(x) - g2(x);
    return ret;
}
 
int main() {
    ll n, k;
    cin >> n >> k;

    ll res=n;
    for(int i=1; i<=k; i++){
        res = dfs(res);
    }
    cout << res << endl;
 
    return 0;
}