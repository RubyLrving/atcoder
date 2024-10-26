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
    string S;
    cin >> S;
    map<char, ll> mp;
    rep(i, S.size()) mp[S[i]]++;

    ll ans=0;
    vector<ll> v(mp.size());
    for(auto m:mp){
        v.push_back(m.second);
        if(m.second>1) ans=1;
    }
    
    for(ll i=0; i<v.size()-1; i++){
        for(ll j=i+1; j<v.size(); j++){
            ans += v[i]*v[j];
        }
    }
    cout << ans << endl;

    return 0;
} 