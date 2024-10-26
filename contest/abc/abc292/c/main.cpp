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

/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

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
    ll N;
    cin >> N;

    map<ll, ll> mp;
    for(ll a = 1; a <= N; a++){
        for(ll b = 1; a * b <= N; b++){
            mp[a * b]++;
        }
    }

    ll ans = 0;
    for(auto m:mp){
        ll X = N - m.first;
        if(mp.find(X) != mp.end()){
            ans += m.second * mp[X];
        }
    }
    cout << ans << endl;

    return 0;
} 