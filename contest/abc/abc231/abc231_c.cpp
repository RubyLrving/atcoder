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

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N), x(Q);
    rep(i, N) cin >> A[i];
    rep(i, Q) cin >> x[i];

    sort(A.begin(), A.end());
    rep(i, Q){
        auto it = lower_bound(A.begin(), A.end(), x[i]);
        int index = it - A.begin();
        cout << A.size() - index << endl;
    }

    return 0;
}