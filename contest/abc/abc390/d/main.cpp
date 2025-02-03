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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> group;
    unordered_set<ll> st;
    auto dfs = [&](auto dfs, int v){
        if(v >= N){
            ll sum = 0;
            int n = group.size();
            rep(i, n){
                sum ^= group[i];
            } 
            st.insert(sum);
            return;
        }

        int n = group.size();
        rep(i, n){
            group[i] += A[v];
            dfs(dfs, v+1);
            group[i] -= A[v];
        }

        group.push_back(A[v]);
        dfs(dfs, v+1);
        group.pop_back();
    };
    dfs(dfs, 0);

    cout << st.size() << endl;
    return 0;
} 
