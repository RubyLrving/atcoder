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
    string R, C;
    cin >> R >> C;

    vector<string> vs(N);
    rep(i, N) rep(j,N){
        vs[i] += '.';
    }

    rep(i, N){
        vs[i][0] = R[i];
    }

    rep(i, N){
        vs[0][i] = C[i];
    }

    if(vs[0][0] != R[0] || vs[0][0] != C[0]){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    rep(i, N) cout << vs[i] << endl;

    return 0;
} 