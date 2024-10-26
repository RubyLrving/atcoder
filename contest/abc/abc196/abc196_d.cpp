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

int H, W, ans;

void dfs(int n, int bit, int A, int B){
    if(n==H*W){
        ans++;
        return;
    }
    if(bit & 1 << n) return dfs(n + 1, bit, A, B);
    if(B) dfs(n+1, bit | 1<<n, A, B-1);
    if(A){
        if(n%W < W-1 && ~bit << n && ~bit << (n+1)) dfs(n+1, bit | 1<<n | 1<<(n+1), A-1, B);
        if(n+W < H*W) dfs(n+1, bit | 1<<n | 1<<(n+W), A-1, B);
    }
}

int main() {
    int A, B;
    cin >> H >> W >> A >> B;

    dfs(0, 0, A, B);

    cout << ans << endl;

    return 0;
}