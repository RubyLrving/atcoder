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

int N;
int res=0;
vector<vector<int>> A;

void dfs(vector<vector<int>> g, int n, int cnt){
    if(n>N) return;
    if(n==6){
        int total=0;
        for(int i=0; i<g.size(); i++){
            int ans=0;
            for(int j=0; j<g[i].size(); j++){
                for(int k=j+1; k<g[i].size(); k++){
                    int a = g[i][j];
                    int b = g[i][k];

                    ans += A[a][b-a];
                }
            }
            if(ans>0) total += ans;
        }
        res = max(res, total);
        return;
    }

    if(n==0 && cnt==0) g.push_back(vector<int>());

    g[cnt].push_back(n);
    dfs(g, n+1, cnt);

        if(cnt+1<3){
        g.push_back(vector<int>());
        dfs(g, n, cnt+1);
    }
}

int main() {
    
    cin >> N;

    A.resize(N-1);
    rep(i, N-1){
        rep(j, N-1-i){
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    dfs(vector<vector<int>>(), 0, 0);

    cout << res << endl;

    return 0;
}