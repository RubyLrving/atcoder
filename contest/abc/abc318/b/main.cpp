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

bool graph[100][100];

int main() {
    int N;
    cin >> N;

    rep(i, N){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for(int y=c; y<d; y++){
            for(int x=a; x<b; x++){
                graph[y][x] = true;
            }
        }
    }

    int ans=0;
    for(int y=0; y<=100; y++){
        for(int x=0; x<100; x++){
            if(graph[y][x]) ans++;
        }
    }
    cout << ans << endl;

    return 0;
} 