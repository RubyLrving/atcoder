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
    vector<string> A(N), B(N, string(N, ' '));
    rep(i, N) cin >> A[i];

    rep(y, N){
        rep(x, N){
            int i = min(min(x, y), min(N - x - 1, N - y - 1));
            if(i%4==0) B[y][N - x - 1] = A[x][y]; // 90
            if(i%4==1) B[N - x - 1][N - y - 1] = A[x][y]; // 180
            if(i%4==2) B[N - y - 1][x] = A[x][y]; // 270
            if(i%4==3) B[x][y] = A[x][y]; // 360
        }
    }

    rep(y, N){
        cout << B[y] << endl;
    }

    return 0;
} 