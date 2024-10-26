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

int N, M;
int A[200010];
int B[200010];
int X[200010];
int check[200010];
int ok = 0;

void dfs(int i){

    if(i>=M){
        ok = 1;
        return;
    }

    if(A[i] == B[i]){
        return;
    }

    if(X[A[i]] == 0 && X[B[i]] == 0){
        if(check[A[i]] == 0){
            X[A[i]] = 1;
            check[A[i]] = 1;
            check[B[i]] = 1;
            dfs(i+1);
            X[A[i]] = 0;
            check[A[i]] = 0;
            check[B[i]] = 0;
        }

        if(check[B[i]] == 0){
            X[B[i]] = 1;
            check[A[i]] = 1;
            check[B[i]] = 1;
            dfs(i+1);
            X[B[i]] = 0;
            check[A[i]] = 0;
            check[B[i]] = 0;
        }
    }else if(X[A[i]] != X[B[i]]){
        check[A[i]] = 1;
        check[B[i]] = 1;
        dfs(i+1);
        check[A[i]] = 0;
        check[B[i]] = 0;
    }
}

int main() {
    cin >> N >> M;
    
    rep(i, M) cin >> A[i];
    rep(i, M) cin >> B[i];

    dfs(0);

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 