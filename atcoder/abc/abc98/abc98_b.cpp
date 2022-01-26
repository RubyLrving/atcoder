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
    string S;
    cin >> N >> S;

    int ans=0;
    repx(n, 0, N-1){
        int l=n;
        set<char> lst;
        rep(i, l+1) lst.insert(S[i]);

        set<char> rst;
        repx(i, l+1, N)  rst.insert(S[i]);

        set<char> result;
        set_intersection(lst.begin(), lst.end(), rst.begin(), rst.end(), inserter(result, result.end()));

        ans = max((int)result.size(), ans);
    }

    cout << ans << endl;

    return 0;
} 