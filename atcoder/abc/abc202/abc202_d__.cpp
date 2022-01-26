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

int A, B, K;
vector<string> st;

void dfs(string s, int a, int b){
    if(a+b >= A+B){
        st.push_back(s);
        return;
    }

    if(a<A) dfs(s+"a", a+1, b);
    if(b<B) dfs(s+"b", a, b+1);
};

int main() {
    cin >> A >> B >> K;

    dfs("", 0, 0);
    sort(st.begin(), st.end());

    cout << st[K-1] << endl;

    return 0;
}