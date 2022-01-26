#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

bool is_prime_number[100001];
int dp[100002];

int main(int argc, const char * argv[]) {
    int q;
    cin >> q;

    is_prime_number[1]=true;
    for(int i=2; i<100001; i++){
        if(!is_prime_number[i]){
            for(int j=i+i; j<100001; j+=i){
                is_prime_number[j] = true;
            }
        }
    }

    for(int i=2; i<100002; i++){
        if(!is_prime_number[i] && !is_prime_number[(i+1)/2]){
            dp[i] = 1;
        }
    }

    for(int i=2; i<100001; i++){
            dp[i] += dp[i-1];
    }

    vector<int> l(q);
    vector<int> r(q);
    rep(i, q){
        cin >> l[i] >> r[i];
    }

    rep(i, q){
        cout << dp[r[i]] - dp[l[i]-1] << endl;
    }

    return 0;
}