#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
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
    ll N, A, B, P, Q, R, S;
    cin >> N >> A >> B;
    cin >> P >> Q >> R >> S;

    for(ll y=P; y<=Q; y++){
        for(ll x=R; x<=S; x++){
            int ok=0;
            if(y-A == x-B){
                if(max(1-A, 1-B) <= y-A && y-A<=min(N-A, N-B)){
                    ok=1;
                }
            }

            if(y-A == -(x-B)){
                if(max(1-A, B-N) <= y-A && y-A<=min(N-A, B-1)){
                    ok=1;
                }
            }

            if(ok) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }

    return 0;
}