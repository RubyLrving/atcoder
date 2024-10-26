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
    int X, Y, Z;
    cin >> X >> Y >> Z;

    if(0 < Z && Z < Y && Y < X){
        cout << abs(X) << endl;
    }else if(0 > Z && 0 < Y && Y < X){
        cout << abs(X) + abs(Z) * 2 << endl;
    }else if(0 < X && Y > X){
        cout << abs(X) << endl;
    }else if(0 < X && Y < 0){
         cout << abs(X) << endl;
    }else if(0 > X && Y < X){
        cout << abs(X) << endl;
    }else if(0 > X && 0 < Y){
        cout << abs(X) << endl;
    }else if(0 > X && Y > X && Z > Y && Z < 0){
        cout << abs(X) << endl;
    }else if(0 > X && Y > X && Z > Y && 0 < Z){
        cout << abs(X) + abs(Z) * 2 << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}


