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
    string s, t;
    cin >> s >> t;

    string atcoder="atcoder";
    int N = s.size();
    int gs=0;
    int gt=0;
    map<char, int> mp;
    rep(i, N){
        if(s[i] != '@') mp[s[i]]++;
        if(t[i] != '@') mp[t[i]]--;
        if(s[i] == '@') gs++;
        if(t[i] == '@') gt++;
    }

    for(P m:mp){
        if(m.second==0) continue;
        if(atcoder.find(m.first) == string::npos){
            cout << "No" << endl;
            return 0;
        }
        if(m.second > 0) gt -= m.second;
        if(m.second < 0) gs += m.second;
    }

    if(gt == gs && gt>=0 && gs>=0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 