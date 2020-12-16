#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    rep(i, m) cin >> a[i];

    sort(a.begin(), a.end());
    a.push_back(n+1);

    int cur=1;
    vector<int> s;
    rep(i, m+1){
        int k = a[i]-cur;
        if(k > 0) s.push_back(k);
        cur = a[i]+1;
    }

    int k=n;
    for(int w:s) k = min(k, w);
    int res = 0;
    for(int w:s) res += (w + k - 1) / k;
    cout << res << endl;

    return 0;
}