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

ll dp[20010][2];

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> C(N);
    rep(i, N) cin >> C[i];
    vector<ll> s0(N+1), s1(N+1), e0(N+1), e1(N+1);

    for(int i=0; i<S.size(); i++){
        s0[i+1] = s0[i];
        s1[i+1] = s1[i];
        if(i%2==0){
            if(S[i] - '0' == 0) s1[i+1] += C[i];
            else s0[i+1] += C[i];
        }else{
            if(S[i] - '0' == 0) s0[i+1] += C[i];
            else s1[i+1] += C[i];
        }
    }

    for(int i = S.size()-1; i>=0; i--){
        e0[i] = e0[i+1];
        e1[i] = e1[i+1];
        if(i%2==0){
            if(S[i] - '0' == 0) e0[i] += C[i];
            else e1[i] += C[i];
        }else{
            if(S[i] - '0' == 0) e1[i] += C[i];
            else e0[i] += C[i];
        }
    }

    ll ans = 2e18;
    for(int i=1; i<S.size(); i++){
        ans = min(ans, min(s0[i] + e0[i], s1[i] + e1[i]));
    }
    cout << ans << endl;

    return 0;
} 