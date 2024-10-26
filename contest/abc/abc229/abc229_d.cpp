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

int main() {
    string S;
    int K;
    cin >> S >> K;

    int N = S.length();
    int cnt=0;
    int res=0;
    queue<char> que;
    rep(i, N){
        que.push(S[i]);
        if(S[i] == '.') cnt++;
        if(cnt>K){
            char c = que.front();
            que.pop();
            if(c == '.') cnt--;
        }
        res = max(res, (int)que.size());
    }
    cout << res << endl;

    return 0;
}