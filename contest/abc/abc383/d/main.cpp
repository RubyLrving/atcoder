#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    ll N;
    cin >> N;
    ll INF = 1001001;
    bool isPrime[INF];
    for(int i=0; i<INF; i++) isPrime[i] = true;
    for(ll i=2; i*i<INF; i++){
        if(isPrime[i] == false) continue;
        for(ll j=i; j*i<INF; j++){
            isPrime[j*i] = false;
        }
    }

    vector<ll> primes;
    for(int i=2; i<INF; i++){
        if(isPrime[i]) primes.push_back(i);
    }

    ll cnt = 0;
    for(auto p1:primes){
        for(auto p2:primes){
            if(p1 <= p2) break;
            if(p1 * p1 * p2 * p2 > N) break;
            cnt++;
        }
    }

    for(auto p:primes){
        ll x = 1;
        rep(i, 8) x *= p;
        if(x > N) break;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
} 
