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
    ll N, M, L, Q;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    cin >> M;
    vector<ll> B(M);
    rep(i, M) cin >> B[i];
    cin >> L;
    vector<ll> C(L);
    rep(i, L) cin >> C[i];
    cin >> Q;
    vector<ll> D(Q);
    rep(i, Q) cin >> D[i];

    set<ll> st;
    rep(i, N){
        rep(j, M){
            rep(k, L){
                st.insert(A[i]+B[j]+C[k]);
            }
        }
    }

    rep(i, Q){
        auto itr = st.find(D[i]);
        if(itr == st.end()) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
} 