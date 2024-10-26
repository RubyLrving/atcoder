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
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    map<char, char> mp;
    rep(i, S.size()) mp[S[i]] = S[i];

    vector<char> C(Q), D(Q);
    rep(i, Q) cin >> C[i] >> D[i];
    rep(i, Q){
        for(auto m:mp){
            if(m.second == C[i]){
                mp[m.first] = D[i];
            }
        }
    }

    rep(i, S.size()) cout << mp[S[i]];
    cout << endl;

    return 0;
} 