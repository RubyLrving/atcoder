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

    string T;
    cin >> T;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> ans;
    rep(i, N){
        int start = 0;
        int end_T = T.size()-1;
        int end_S = S[i].size()-1;
        int cnt = 0;

        if(T.size() < S[i].size()-1 || T.size() > S[i].size() + 1) continue;

        while(S[i][start] == T[start] && start<min(T.size(), S[i].size())) cnt++, start++;

        while(S[i][end_S] == T[end_T] && end_T>=0 && end_S>=0) cnt++, end_T--, end_S--;

        if(cnt>=T.size()-1 && cnt>=S[i].size()-1) ans.push_back(i+1);
    }

    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i] << ' ';

    return 0;
} 