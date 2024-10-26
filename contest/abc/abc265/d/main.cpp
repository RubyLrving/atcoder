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
    ll N, P, Q, R;
    cin >> N >> P >> Q >> R;

    set<ll> st;
    st.insert(0);
    ll sum = 0;   
    for(int i=0; i<N; i++){
        ll a;
        cin >> a;
        sum += a;
        st.insert(sum);
    }

    for(auto x:st){
        if(st.find(x+P) != st.end() && st.find(x+P+Q) != st.end() && st.find(x+P+Q+R) != st.end()){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
} 