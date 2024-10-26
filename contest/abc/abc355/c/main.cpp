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
    int N, T;
    cin >> N >> T;
    vector<int> A(T);
    rep(i, T) cin >> A[i];

    vector<int> H(N+1), W(N+1);
    set<P> X, Y;
    repx(i, 1, N+1) X.insert(P(i, i));
    repx(i, 1, N+1) Y.insert(P(i, (N+1)-i));

    rep(i, T){

        int t = A[i];
        int y = (t - 1) / N + 1;
        int x = t % N;
        if(x==0) x=N;

        //cout << y << ' ' << x << endl;

        H[y] += 1;
        W[x] += 1;
        X.erase(P(y, x));
        Y.erase(P(y, x));
        
        int ok = 0;
        repx(i, 1, N+1){
            if(W[i] == N) ok = 1;
            if(H[i] == N) ok = 1;
        }
        if(X.size() == 0) ok = 1;
        if(Y.size() == 0) ok = 1;

        if(ok){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
} 