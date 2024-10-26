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

int N;
string S;
int W[200000+1];
vector<int> child, parent;

int f(int X){
    int t1=0, t2=0;
    auto itr1 = lower_bound(child.begin(), child.end(), X);
    if(itr1 != child.end()) t1 = itr1 - child.begin();
    else t1 = child.size();
    auto itr2 = lower_bound(parent.begin(), parent.end(), X);
    if(itr2 != parent.end()) t2 += parent.end() - itr2;
    return t1+t2;
}

int main() {
    cin >> N >> S;
    rep(i, N) cin >> W[i];

    rep(i, N){
        if(S[i] == '0') child.push_back(W[i]);
        else parent.push_back(W[i]);
    }
    sort(child.begin(), child.end());
    sort(parent.begin(), parent.end());

    int ans=0;
    rep(i, N){
        if(S[i] == '0') ans = max(ans, f(W[i]+1));
        else ans = max(ans, f(W[i]));
    }
    cout << ans << endl;

    return 0;
} 