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

string atcoder = "atcoder";

int main() {
    string s;
    cin >> s;

    int n=s.size();
    int offset=0;
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(s[j] == atcoder[offset]){
                for(int k=j; k>=offset+1; k--){
                    swap(s[k], s[k-1]);
                    ans++;
                }
            }
        }
        offset++;
    }
    cout << ans << endl;

    return 0;
} 