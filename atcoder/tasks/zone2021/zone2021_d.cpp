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

string t;

P dfs(int f, int b){
    if(f<0 || t.length() <= b) return P(f+1, b-1);

    if(t[f] == t[b]){
        return dfs(f-1, b+1);
    }

    return P(f+1, b-1);
};

int main() {
    string s;
    cin >> s;

    
    bool cnt=false;
    rep(i, s.length()){
        if(s[i] == 'R'){
            cnt=!cnt;
        }else{
            if(cnt==false){
                if(t[t.length()-1] == s[i]) t.erase(t.length()-1, 1);
                else t += s[i];
            }else{
                if(t[0] == s[i]) t.erase(0, 1);
                else t = s[i] + t;
            }
        }
    }

    if(cnt) reverse(t.begin(), t.end());

    cout << t << endl;

    return 0;
}