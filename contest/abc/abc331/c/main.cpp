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
    int N;
    cin >> N;
    vector<ll> A(N), AA(N), AAA(N+1);
    rep(i, N) cin >> A[i], AA[i] = A[i];
    sort(AA.begin(), AA.end());
    rep(i, N) AAA[i+1] = AA[i] + AAA[i];

    rep(i, N){
        ll p = A[i];
        auto itr = upper_bound(AA.begin(), AA.end(), p);
        int index = itr - AA.begin();
        cout << AAA[N] - AAA[index];
        if(i<N-1) cout  << ' ';
    }
    cout << endl;

    return 0;
} 