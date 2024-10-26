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

int N, K;
vector<vector<int>> ans;

void dfs(vector<int>& R, int n, vector<int>& v){
    if(n <= 0){
        int sum = 0;
        rep(i, N) sum += v[i];
        if(sum % K == 0){
            vector<int> to(N);
            copy(v.begin(), v.end(), to.begin());
            ans.push_back(to);
        }
        return;
    }

    for(int i=1; i<=R[N-n]; i++){
        v.push_back(i);
        dfs(R, n-1, v);
        v.pop_back();
    }
}

int main() {
    cin >> N >> K;
    vector<int> R(N);
    rep(i, N) cin >> R[i];

    vector<int> v;
    dfs(R, N, v);

    for(auto a:ans){
        int n = a.size();
        for(int i=0; i<n; i++){
            cout << a[i];
            if(i<n-1) cout << ' ';
            else cout << endl;
        }
    }

    return 0;
} 