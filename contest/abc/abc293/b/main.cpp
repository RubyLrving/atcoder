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
    vector<int> X(N), A(N);
    rep(i, N) cin >> X[i];
    rep(i, N){
        if(A[i] == 1) continue;
        int a = X[i] - 1;
        A[a] = 1;
    }

    int cnt = 0;
    string ans;
    rep(i, N){
        if(A[i] == 0){
            ans += to_string(i+1) + " ";
            cnt++;
        }
    }
    cout << cnt << endl;
    cout << ans.substr(0, ans.size()-1) << endl;

    return 0;
} 