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

char filed[729][729];

void dfs(int K, int N, int p, int q){

    if(N<=0) return;

    int s = K / 3;
    int e = K / 3 * 2;

    repx(y, s, e){
        repx(x, s, e){
            filed[p + y][q + x] = '.';
        }       
    }
    rep(i, 3){
        rep(j, 3){
            dfs(K / 3, N - 1, p + s * i, q + s * j);
        }
    }

}

int main() {
    int N;
    cin >> N;
    int K = pow(3, N);
    rep(i, K) rep(j, K) filed[i][j] = '#';

    dfs(K, N, 0, 0);

    rep(i, K){
        rep(j, K){
            cout << filed[i][j];
        }
        cout << endl;
    }

    return 0;
} 