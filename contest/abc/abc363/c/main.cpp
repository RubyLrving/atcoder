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
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    sort(s.begin(), s.end());

    int ans = 0;
    do {
        int ok = 1;
        for(int i=0; i<=N-K; i++){
            string a, b;
            for(int j=0; j<K; j++){
                a += s[i+j];
                b += s[i+K-j-1];
            }
            if(a==b) ok=0;
        }
        if(ok) ans++;
        
    } while (next_permutation(s.begin(), s.end()));
    
    cout << ans << endl;

    return 0;
} 