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

    vector<string> A(N);
    vector<string> ans(N);
    rep(i, N){
        cin >> A[i];
        ans[i] = A[i];
    }

    rep(i, N){
        rep(j, N){
            if(i==0){
                if(j==0){
                    ans[i][j] = A[i+1][j];
                }else{
                    ans[i][j] = A[i][j-1];
                }
            }

            if(i==N-1){
                if(j==N-1){
                    ans[i][j] = A[i-1][j];
                }else{
                    ans[i][j] = A[i][j+1];
                }
            }

            if(j==0){
                if(i==N-1){
                    ans[i][j] = A[i][j+1];
                }else{
                    ans[i][j] = A[i+1][j];
                }
            }  

            if(j==N-1){
                if(i==0){
                    ans[i][j] = A[i][j-1];
                }else{
                    ans[i][j] = A[i-1][j];
                }
            }       
        }
    }

    rep(i, N){
        cout << ans[i] << endl;
    }

    return 0;
} 