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
    vector<int> T(Q), A(Q), B(Q);
    rep(i, Q) cin >> T[i] >> A[i] >> B[i];

    map<int, set<int>> P;
    rep(i, Q){
        if(T[i] == 1){
            P[A[i]].insert(B[i]);
        }
        if(T[i] == 2){
            P[A[i]].erase(B[i]);
        }
        if(T[i] == 3){
            if(P[A[i]].find(B[i]) != P[A[i]].end() && P[B[i]].find(A[i]) != P[B[i]].end()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
} 