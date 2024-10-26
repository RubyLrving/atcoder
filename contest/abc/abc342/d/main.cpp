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

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
ll divisor(long long n) {
    if(n==0 || n == 1) return n;

    map<ll, ll> ret;
    long long i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            ret[i]++;
            n /= i;
        }else{
            i++;
        }
    }
    if(n!=1) ret[n]++;
    ll sum = 1;
    for(auto r:ret) if(r.second%2==1) sum *= r.first;
    if(sum==1) sum=-1;
    return sum;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    
    map<ll, ll> mp;
    rep(i, N){
        ll d = divisor(A[i]);
        mp[d]++;
    }

    ll ans=0;
    for(auto m:mp){
        if(m.first==0){
            ans += (A.size()-m.second) * m.second;
            ans += nCr(m.second, 2);
        }else if(m.first==1){
            ans += nCr(m.second, 2);
            ans += mp[-1] * m.second;
        }else if(m.first==-1){
            ans += nCr(mp[-1], 2);
        }else{
            ans += nCr(m.second, 2);
        }
        //cout << ans << ' ' << m.first << endl;
    }
    cout << ans << endl;

    return 0;
} 