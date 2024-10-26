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

    if(pow(10, 3) <= N && N <= pow(10, 4) - 1){
        N = N / 10 * 10;
    }else if(pow(10, 4) <= N && N <= pow(10, 5) - 1){
        N = N / 100 * 100;
    }else if(pow(10, 5) <= N && N <= pow(10, 6) - 1){
        N = N / 1000 * 1000;
    }else if(pow(10, 6) <= N && N <= pow(10, 7) - 1){
        N = N / 10000 * 10000;
    }else if(pow(10, 7) <= N && N <= pow(10, 8) - 1){
        N = N / 100000 * 100000;
    }else if(pow(10, 8) <= N && N <= pow(10, 9) - 1){
        N = N / 1000000 * 1000000;
    }
    cout << N << endl;

    return 0;
} 