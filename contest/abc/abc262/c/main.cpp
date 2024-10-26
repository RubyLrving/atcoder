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

// nCr を定義通りに求める関数
long long nCr(long long n, long long r) {
	long long nPr = 1;
	for(long long i = 0; i < r; ++i) {
		nPr *= (n - i);
	}

	long long fact_r = 1;
	for(long long i = 1; i <= r; ++i) {
		fact_r *= i;
	}

	long long ret = nPr / fact_r;
	return ret;
}

int main() {
    ll N, sum=0;
    cin >> N;
    vector<ll> A(N+1);
    rep(i, N){
        ll v;
        cin >> v;
        A[i+1] = v;
        if(i+1 == v) sum++;
    }

    ll ans=0;
    for(int i=1; i<A.size(); i++){
        if(A[i] != i){
            int t = A[i];
            if(A[t] == i) ans++;
        }
    }
    ans /= 2;
    ans += nCr(sum, 2);
    cout << ans << endl;

    return 0;
} 