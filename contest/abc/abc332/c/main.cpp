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
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int logo = 0;
    int logoT = 0;
    int t = 0;
    for(int i=0; i<N; i++){
        if(S[i] == '2'){
            logo++;
        }
        if(S[i] == '1'){
            if(t<M) t++;
            else logo++;
        }
        if(S[i] == '0'){
            logo = 0;
            t = 0;
        }
        logoT = max(logoT, logo);
    }
    cout << logoT << endl;

    return 0;
} 