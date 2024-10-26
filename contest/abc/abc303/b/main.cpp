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
    vector<vector<int>> A(M, vector<int>(N));
    rep(i, M) rep(j, N){
        cin >> A[i][j];
    }

    vector<set<int>> graph(N, set<int>());
    rep(i, M){
        rep(j, N - 1){
            int a = A[i][j]-1;
            int b = A[i][j+1]-1;
            graph[a].insert(b);
            graph[b].insert(a);
        }
    }

    int ans = 0;
    rep(i, N){
        ans += N - graph[i].size() - 1;
    }
    cout << ans / 2 << endl;

    return 0;
} 