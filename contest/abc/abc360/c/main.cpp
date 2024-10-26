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
    vector<int> A(N), W(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> W[i];

    map<int, int> mp;
    int ans = 0;
    rep(i, N){
        if(mp.find(A[i]) != mp.end()){
            if(mp[A[i]] < W[i]){
                ans += mp[A[i]];
                mp[A[i]] = W[i]; 
            }else{
                ans += W[i];
            }
        }else{
            mp[A[i]] = W[i]; 
        }
    }
    cout << ans << endl;

    return 0;
} 