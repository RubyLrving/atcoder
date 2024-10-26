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
    string S;
    cin >> S;

    int cnt = 0;
    for(int i=2; i<N; i++){
        if(S[i-2] == 'A' && S[i-1] == 'B' && S[i] == 'C') cnt++;
    }

    vector<int> X(Q);
    vector<char> C(Q);
    rep(i, Q){
        cin >> X[i] >> C[i];
        X[i]--;
    }

    rep(i, Q){
        for(int j=max(2, X[i]); j<min(X[i]+3, N); j++){
            if(S[j-2] == 'A' && S[j-1] == 'B' && S[j] == 'C') cnt--;
        } 
        S[X[i]] = C[i];
        for(int j=max(2, X[i]); j<min(X[i]+3, N); j++){
            if(S[j-2] == 'A' && S[j-1] == 'B' && S[j] == 'C') cnt++;
        }
        cout << cnt << endl; 
    }

    return 0;
} 