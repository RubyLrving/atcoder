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

ll res=0;
vector<int> A;

void dfs(int cnt, vector<int> tmp){
    if(cnt >= A.size()){
        if(tmp.size()<2) return;
        
        int n = tmp.size()-1;
        if(tmp[0] <= tmp[n]){
            res = (res + 1) % 998244353; 
        }
        return;
    }

    dfs(cnt+1, tmp);

    tmp.push_back(A[cnt]);
    dfs(cnt+1, tmp);
}

int main() {
    int N;
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    dfs(0, vector<int>());

    cout << res << endl;

    return 0;
}