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
    int Q;
    cin >> Q;

    multiset<ll> st;
    multiset<ll>::iterator it;
    rep(i, Q){
        ll c, x, k;
        cin >> c;
        if(c==1){
            cin >> x;
            st.insert(x);
        }else if(c==2){
            cin >> x >> k;
            it = st.upper_bound(x);
            while(k>0){
                if(st.begin() == it) break;
                it--;
                k--;
            }
            if(k==0 && st.end() != it) cout << *it << endl;
            else cout << -1 << endl;
        }else{
            cin >> x >> k;
            it = st.lower_bound(x);
            k--;
            while(k>0){
                if(st.end() == it) break;
                it++;
                k--;
            }
            if(k==0 && st.end() != it) cout << *it << endl;
            else cout << -1 << endl;
        }
    }


    return 0;
} 