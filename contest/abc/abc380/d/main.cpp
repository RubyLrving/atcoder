#include <bits/stdc++.h>
#include <atcoder/all>
 
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
    string S, T;
    cin >> S;
    ll Q;
    cin >> Q;
    vector<ll> K(Q);
    rep(i, Q) cin >> K[i];

    int N = S.size();
    rep(i, Q){
        ll k = K[i] - 1;
        ll num = k / N;
        ll index = k % N;
        
        if(popcount((unsigned long long)num) % 2 == 0){
            cout << S[index];
        }else{
            if(isupper(S[index])) cout << (char)(S[index] + 32);
            else cout << (char)(S[index] - 32);
        }

        if(i < Q-1) cout << ' ';
        else cout << endl;
    }

    return 0;
} 