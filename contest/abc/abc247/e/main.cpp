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
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int ans=0;
    rep(i, N){
        int l=0, OF=0; 
        if(A[i] == X){
            l = i;
            OF=1;
        }else if(A[i] == Y){
            l = i;
            OF=0;
        }else{
            continue;
        }
        repx(j, i+1, N){
            if(A[j]<Y || X<A[i]){
                OF=-1;
                break;
            }

            if(OF==1){
                if(A[j]==Y){
                    OF=2;
                    ans++;
                }
            }else if(OF==0){
                if(A[j]==X){
                    OF=2;
                    ans++;
                }
            }else{
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
} 