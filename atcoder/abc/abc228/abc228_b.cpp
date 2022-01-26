#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
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
    int N, X;
    cin >> N >> X;
    X--;

    vector<int> A(N);
    vector<int> T(N);
    rep(i, N){
        cin >> A[i];
        A[i] = A[i] - 1;
        T[i] = 0;
    }

    int res=0;
    while(T[X] == 0){
        T[X] = 1;
        X = A[X];
        res++;
    }
    cout << res << endl;

    return 0;
}