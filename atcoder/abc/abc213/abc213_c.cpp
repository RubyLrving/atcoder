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

int field[100000];
int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<int> A(N);
    vector<int> B(N);
    rep(i, N) cin >> A[i] >> B[i];
    vector<int> ys;
    rep(i, N) ys.push_back(A[i]);
    sort(ys.begin(), ys.end());
    ys.erase( unique(ys.begin(), ys.end()), ys.end());
    rep(i, N) A[i] = lower_bound(ys.begin(), ys.end(), A[i]) - ys.begin() + 1;

    vector<int> xs;
    rep(i, N) xs.push_back(B[i]);
    sort(xs.begin(), xs.end());
    xs.erase( unique(xs.begin(), xs.end()), xs.end());
    rep(i, N) B[i] = lower_bound(xs.begin(), xs.end(), B[i]) - xs.begin()+ 1;

    rep(i, N) cout << A[i] << " " << B[i] << endl;

    return 0;
}