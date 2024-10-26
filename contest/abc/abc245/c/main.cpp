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
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    vector<set<int>> vec(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    vec[0].insert(A[0]);
    vec[0].insert(B[0]);

    repx(i, 1, N){
        for(auto v:vec[i-1]){
            if(abs(v - A[i]) <= K){
                vec[i].insert(A[i]);
            }
            if(abs(v - B[i]) <= K){
                vec[i].insert(B[i]);
            }
        }
    }

    if(vec[N-1].size()>0) cout << "Yes" << endl;
    else cout << "No" << endl;
     
    return 0;
} 