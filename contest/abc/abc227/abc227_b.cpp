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
    int N;
    cin >> N;

    vector<int> S(N);
    rep(i, N) cin >> S[i];

    int res=0;
    rep(i, N){
        for(int a=1; 3*a + 4*a<=S[i]; a++){
            int ok=0;
            for(int b=1; 3*a + 4*b*a + 3*b<=S[i]; b++){
                if(3*a + 4*b*a + 3*b == S[i]){
                    res++;
                    ok=1;
                    break;
                }
            }
            if(ok) break;
        }
    }
    cout << S.size() - res << endl;

    return 0;
}