#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
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

vector<int> T;
vector<vector<int>> A;
vector<int> F;
ll res=0;

void dfs(int cnt){
    if(F[cnt]==0){
        F[cnt]=1;
        res += T[cnt];
    }

    if(A[cnt].size() == 0){
        return;
    }

    rep(i, A[cnt].size()){
        int a = A[cnt][i]-1;
        if(F[a] == 1) continue;
        dfs(A[cnt][i]-1);
    }
}

int main() {
    int N;
    cin >> N;

    T.resize(N);
    A.resize(N);
    F.resize(N);
    rep(i, N){
        int K;
        cin >> T[i] >> K;

        A[i].resize(K);
        rep(j, K) cin >> A[i][j];
    }

    dfs(N-1);

    cout << res << endl;

    return 0;
}