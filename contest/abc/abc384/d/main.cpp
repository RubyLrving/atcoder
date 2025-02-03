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
    ll N, S;
    cin >> N >> S;
    vector<ll> a(N), aa(N*2);
    rep(i, N) cin >> a[i];
    ll total = 0;
    rep(i, N) total += a[i];
    rep(i, N*2) aa[i] = a[i%N];
    S = S % total;
    if(S == 0){
        cout << "Yes" << endl;
        return 0;
    }

    ll right = 0;
    ll sum = 0;
    rep(left, aa.size()){
        while(right < aa.size() && sum < S){
            sum += aa[right];
            right++;
        }

        if(sum == S){
            cout << "Yes" << endl;
            return 0;
        }
        sum -= aa[left];
    }
    cout << "No" << endl;

    return 0;
} 
