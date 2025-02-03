#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    rep(i, N-1) A[i+1] = min(A[i+1], A[i]);

    rep(i, M){
        int index = lower_bound(A.begin(), A.end(), B[i], greater<int>()) - A.begin();
        if(index == N) cout << -1 << endl;
        else cout << index+1 << endl;
    }

    return 0;
} 
