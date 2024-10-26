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

int X[4] = {1, 0, -1, 0};
int Y[4] = {0, -1, 0, 1};

int main() {
    int N;
    string t;
    cin >> N >> t;

    int cnt=0, x=0, y=0;
    rep(i, N){
        if(t[i] == 'S'){
            x += X[cnt];
            y += Y[cnt];
        }else{
            cnt++;
            if(cnt>=4) cnt=0;
        }
    }
    cout << x << ' ' << y << endl;

    return 0;
} 