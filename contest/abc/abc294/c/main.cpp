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
    vector<int> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    vector<P> C;
    rep(i, N) C.push_back(P(A[i], 0));
    rep(i, M) C.push_back(P(B[i], 1));
    sort(C.begin(), C.end());

    vector<int> AI, BI;
    rep(i, N+M){
        if(C[i].second == 0) AI.push_back(i+1);
        if(C[i].second == 1) BI.push_back(i+1);
    }
    rep(i, N){
        cout << AI[i];
        (i<N-1)? cout << ' ': cout << endl;
    }
    rep(i, M){
        cout << BI[i];
        (i<M-1)? cout << ' ': cout << endl;
    }

    return 0;
} 