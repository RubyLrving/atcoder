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
    int h, m;
    cin >> h >> m;

    while(1){
        int th = h - h % 10 + m / 10;
        int tm = h % 10 * 10 + m % 10;

        if(th < 24 && tm < 60){
            cout << h << ' ' << m << endl;
            break;
        }

        m++;
        if(m>=60) m=0, h++;
        if(h>=24) h=0;
    }

    return 0;
} 