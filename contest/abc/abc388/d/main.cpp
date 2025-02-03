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
    int N;
    cin >> N;
    vector<int> A(N, 0), B(N+1, 0);

    rep(i, N) cin >> A[i];
    rep(i, N){
        A[i] += B[i];
        B[i+1] += B[i] + 1;
        B[min(i + A[i] + 1, N)]--;
        A[i] = max(0, A[i] - (N - 1 - i));
    }

    rep(i, N){
        cout << A[i];
        if(i<N-1) cout << ' ';
        else cout << endl;
    }
    
    return 0;
} 
