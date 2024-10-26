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
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    rep(i, N) cin >> V[i];

    int res = 0;
    rep(L, N+1) rep(R, N+1){
        if(L + R > N) continue;
        int diff = K - (L + R);
        if(diff < 0) continue;

        vector<int> has;
        rep(i, L) has.push_back(V[i]);
        rep(i, R) has.push_back(V[N - 1 - i]);
        sort(has.begin(), has.end());

        int sum = 0;
        int n = has.size();
        rep(i, n) sum += has[i];
        rep(i, min(diff, n)){
            if(has[i] < 0) sum -= has[i];
        }
        res = max(res, sum);
    }
    cout << res << endl;

    return 0;
} 