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

/* 
name: modPow
proc: 高速なべき乗
*/
ll modPow(ll a, ll n, ll mod){
    ll res = 1;
    while(n>0){
        if(n&1) res = res * a % mod;
        a = a * a % mod;
        n = n>>1;
    }
    return res;
}

int main() {
    ll MAX_V = NUM_MAX;
    ll N;
    cin >> N;
    
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    stack<ll> st;
    st.push(A[0]);

    repx(i, 1, N){
        ll a = A[i];
        ll b = st.top();

        if(a != b){
            st.push(a);
            continue;
        }
        st.pop();

        while(a == b){
            
            st.push(b+1);

            if(st.size()<2) break;
            
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
        }

        if(a != b){
            st.push(b);
            st.push(a);
        }
    }
    
    cout << st.size() << endl;

    return 0;
} 