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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    ll cnt = 0;
    vector<ll> AA(N+1);
    rep(i, N){
        AA[i+1] = AA[i] + A[i];
        auto itr = lower_bound(A.begin() + i + 1, A.end(), 100000000 - A[i]);
        cnt += (A.end() - itr);
    }
    ll total = 0;
    rep(i, N){
        total += A[i] * (N - (i+1)) + AA[N] - AA[i+1];
        // cout << N - i+1 << ' ' << N << ' ' << i+1 << endl;
        // cout <<  A[i] * (N - i+1) << ' ' << AA[N] - AA[i+1] << endl;
        // cout << total << endl;
    }
    cout << total - 100000000 * cnt << endl;

    return 0;
} 