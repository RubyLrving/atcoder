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
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<P> A(N), B(N), AB(N);
    rep(i, N){
        cin >> A[i].first;
        A[i].second = i+1;
    }
    rep(i, N){
        cin >> B[i].first;
        B[i].second = i+1;         
    }
    rep(i, N){
        AB[i].first = A[i].first + B[i].first;
        AB[i].second = i+1;
    }

    set<int> st;
    sort(A.begin(), A.end(), [](auto &x, auto &y){
        return x.first == y.first? x.second < y.second : x.first > y.first;
    });
    sort(B.begin(), B.end(), [](auto &x, auto &y){
        return x.first == y.first? x.second < y.second : x.first > y.first;
    });
    sort(AB.begin(), AB.end(), [](auto &x, auto &y){
        return x.first == y.first? x.second < y.second : x.first > y.first;
    });

    int cnt=0;
    for(auto a:A){
        if(cnt>=X) break;
        st.insert(a.second);
        cnt++;
    }
    cnt=0;
    for(auto b:B){
        if(st.find(b.second) != st.end()) continue;
        if(cnt>=Y) break;
        st.insert(b.second);
        cnt++;
    }
    cnt=0;
    for(auto ab:AB){
        if(st.find(ab.second) != st.end()) continue;
        if(cnt>=Z) break;
        st.insert(ab.second);
        cnt++;
    }
    for(auto s:st){
        cout << s << endl;
    }

    return 0;
} 