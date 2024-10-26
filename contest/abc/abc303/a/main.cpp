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
    string S, T;
    cin >> N >> S >> T;

    rep(i, N){
        if(S[i] == 'l') S[i] = '1';
        if(T[i] == 'l') T[i] = '1';
        if(S[i] == 'o') S[i] = '0';
        if(T[i] == 'o') T[i] = '0';
    }

    rep(i, N){
        if(S[i] != T[i]){
            cout << "No" << endl;
            return 0;
        } 
    }

    cout << "Yes" << endl;
    return 0;
} 