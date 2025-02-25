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
    string S;
    cin >> S;

    int ans = 0;
    for(int i=1; i<N-1; i++){
        set<char> st1, st2;
        int res = 0;
        for(int j = 0; j < i; j++){
            st1.insert(S[j]);
        }
        for(int j = i; j < N; j++){
            st2.insert(S[j]);
        }
        for(auto s:st1){
            if(st2.count(s)) res++;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;

    return 0;
} 