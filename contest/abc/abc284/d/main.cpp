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

int prime[100000000];

int main() {
    int N = 100000000;
	for(int i=2; i<=N; i++){
		if(prime[i]) continue;
		for(int j=i+i; j<=N; j+=i){
			prime[j] = true;
		}
	}

    ll T;
    cin >> T;

    rep(i, T){
        ll test;
        cin >> test;
		ll ok=1;
		ll ng=100000000;
		while(abs(ok-ng)>1){
			ll mid=(ok+ng)/2;
			if(test / mid / mid <= 100000000 && test / mid / mid >= 2 && !prime[test / mid / mid]){
				ok = mid;
			}else{ 
				ng = mid-1;
			}
		}
		cout << ok << endl;
    }

    return 0;
} 