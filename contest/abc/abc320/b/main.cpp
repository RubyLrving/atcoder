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
    string S;
    cin >> S;
    int N = S.size();

    int ans = 1;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<=N; j++){

            string t;
            for(int k = i; k<j; k++) t += S[k];

            int n = t.size();
            int ok = 1;
            for (int k = 0; k < n; k++) if (t[k] != t[n - k - 1]) ok = 0;

            if(ok){
                ans = max(ans, j - i);
            }

        }
    }
    cout << ans << endl;

    return 0;
}