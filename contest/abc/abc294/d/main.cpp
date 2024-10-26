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
    int N, Q;
    cin >> N >> Q;
    set<int> people;
    rep(i, N) people.insert(i+1);

    vector<P> v(Q);
    for(int i=0; i<Q; i++){
        int q=0, x=0;
        cin >> q;
        if(q == 2) cin >> x;
        v[i] = P(q, x);
    }

    set<int> st;
    for(int i=0; i<Q; i++){
        int q = v[i].first;
        int x = v[i].second;;

        if(q == 1){
            int p = *people.begin();
            st.insert(p);
            people.erase(p);
        }
        if(q == 2){
            st.erase(x);
        }
        if(q == 3){
            cout << *st.begin() << endl;
        }
    }

    return 0;
} 