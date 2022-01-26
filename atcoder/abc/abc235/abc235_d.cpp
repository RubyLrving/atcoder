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
    ll a, N;
    cin >> a >> N;
    ll M=1;
    while(M<N) M*=10;

    vector<ll> dp(M+1, -1);
    queue<ll> que;
    que.push(1);
    dp[1] = 0;
    while(que.size()){
        ll p = que.front();
        que.pop();

        ll d = p*a;
        if(d<M && dp[d]==-1){
            dp[d] = dp[p] + 1;
            que.push(d);
        }
        if(p%10 != 0 && p>=10){
            string s = to_string(p);
            s = s[s.size()-1] + s.substr(0,s.size()-1);
            ll pp = stoi(s);
            if(pp<M && dp[pp]==-1){
                dp[pp] = dp[p] + 1;
                que.push(pp);
            }
        }
    }
    cout << dp[N] << endl;

    return 0;
}