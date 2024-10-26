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
    int N;
    cin >> N;
    vector<pair<int, int>> p;
    rep(i, N){
        int l, r;
        cin >> l >> r;
        p.emplace_back(l, 0);
        p.emplace_back(r, 1);
    }
    sort(p.begin(), p.end());

    long long rs = 0;
    long long ans = N * (N-1) / 2;
    for(auto [x, y]:p){
        if(y==0) ans -= rs;
        else rs++;
    }
    cout << ans << endl;

    return 0;
} 