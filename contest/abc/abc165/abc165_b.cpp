#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int n, m, q;
vector<int> a, b, c, d;

ll score(const vector<int> &A){
    ll res=0;
    rep(i, q) if(A[b[i]] - A[a[i]] == c[i]) res += d[i];
    return res;
}

ll dfs(vector<int> &A){
    if(A.size() == n){
        return score(A);
    }

    ll res=0;
    int prev_last = (A.empty()? 0:A.back());
    for(int add=prev_last; add<m; add++){
        A.push_back(add);
        res = max(res, dfs(A));
        A.pop_back();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cin >> n >> m >> q;

    a.resize(q), b.resize(q), c.resize(q), d.resize(q);
    rep(i, q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }

    vector<int> A;
    cout << dfs(A) << endl;

    return 0;
}