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

set<string> se;
string str;

void dfs(string s, int c){
    if(s.length() >= 4){
        se.insert(s);
        return;
    }
    if(str.length() <= c){
        return;
    }

    rep(i, str.length()){
        if(str[i] == 'o' || str[i] == '?'){
            dfs(s + to_string(i), c+1);
        }
    }
}

int main() {
    cin >> str;

    dfs("", 0);

    string t;
    rep(i, str.length()){
        if(str[i] == 'o') t += to_string(i);
    }

    ll res=0;
    for(const auto& itr:se){
        ll cnt=0;
        rep(i, t.length()){
            if(itr.find(t[i]) == std::string::npos) break;
            cnt++;
        }
        if(cnt==t.length()) res++;
    }
    cout << res << endl;

    return 0;
}