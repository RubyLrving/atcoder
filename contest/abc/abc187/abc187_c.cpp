#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

void solve(vector<string> str1, vector<string> str2){
    string res = "";
    map<string, string> m;
    rep(i, str1.size()) m["!" + str1[i]] = str1[i];

    rep(i, str2.size()){
        if(m.find(str2[i]) != m.end()){
            res = m[str2[i]];
        }
    }

    if(res == "") cout << "satisfiable" << endl;
    else cout << res << endl;
}

int main() {
    int n;
    cin >> n;

    vector<string> str1;
    vector<string> str2;
    rep(i, n){
        string s;
        cin >> s;
        if(s[0] == '!') str2.push_back(s);
        else str1.push_back(s);
    }

    /*rep(i, 200000){
        if(i%2==0) str2.push_back("a");
        else str1.push_back("!a");
    }*/

    solve(str1, str2);

    return 0;
}