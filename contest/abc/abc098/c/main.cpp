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
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> W(N+1), E(N+1);
    for(int i=0; i<N; i++){
        if(S[i] == 'W') W[i+1] = W[i] + 1;
        else W[i+1] = W[i];
        if(S[i] == 'E') E[i+1] = E[i] + 1;
        else E[i+1] = E[i];
    }

    int ans = N;
    for(int i=0; i<N; i++){
        ans = min(ans, W[i] + E[N] - E[i+1]);
    } 
    cout << ans << endl;

    return 0;
} 