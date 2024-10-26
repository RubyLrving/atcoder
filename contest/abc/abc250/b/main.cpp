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

char graph[101][101];

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    //縦のタイルのループ
    for(int i=0; i<N; i++){
        //横のタイルのループ
        for(int j=0; j<N; j++){
            char m;
            //縦の偶数、奇数をパターン分け
            if(i%2==0){
                //横の偶数、奇数をパターン分け
                if(j%2 == 0) m = '.';
                else m = '#';
            }else{
                if(j%2 == 0) m = '#';
                else m = '.';
            }

            //縦のタイルi個の分だけ、i*Aマスを加算する
            //横のタイルj個の分だけ、j*Bマスを加算する
            for(int a=0; a<A; a++) for(int b=0; b<B; b++){
                graph[i*A + a][j*B + b] = m; 
            }
        }
    }

    for(int i=0; i<N*A; i++){
        for(int j=0; j<N*B; j++){
            cout << graph[i][j];
        }
        cout << endl;
    }

    return 0;
} 