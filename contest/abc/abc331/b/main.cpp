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
    int N, S, M, L;
    cin >> N >> S >> M >> L;

    int ans=1000000010;

    for(int s=0; s*6<=N+6; s++){
        for(int m=0; s*6+m*8<=N+8; m++){
            for(int l=0; s*6+m*8+l*12<=N+12; l++){
                if(s*6+m*8+l*12>=N) ans = min(ans, s*S + m*M + l*L);
            }
        }
    }
    cout << ans << endl;

    return 0;
} 