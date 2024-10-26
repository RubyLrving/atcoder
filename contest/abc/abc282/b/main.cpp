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
    vector<int> A(N), ans;
    rep(i, N) cin >> A[i];

    rep(i, N-1){
        
        ans.push_back(A[i]);

        if(A[i]-A[i+1] > 1){
            for(int j=1; j<=abs(A[i]-A[i+1]); j++){
                ans.push_back(A[i]+j);
            }
        }else if(A[i]-A[i+1] < -1){
            for(int j=1; j<=abs(A[i]-A[i+1]); j++){
                ans.push_back(A[i]-j);
            }
        }
    }
    ans.push_back(A[N-1]);

    rep(i, ans.size()){
        cout << ans[i];
        if(ans.size()-1 != i) cout << ' ';
    }

    return 0;
} 