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

vector<pair<char,int>> func(string s){
    vector<pair<char,int>> res;
    string temp;
    for(int  i=0; i<s.size(); i++){
        if(temp.size()>0){
            if(temp[0] == s[i]){
                temp += s[i];
            }else{
                res.push_back({temp[0], temp.size()});
                temp = "";
                temp = s[i];
            }
        }else{
            temp += s[i];
        }
    }
    res.push_back({temp[0], temp.size()});
    return res;
}

int main() {
    string s, t;
    cin >> s >> t;

    vector<pair<char,int>> S, T;
    S = func(s);
    T = func(t);

    if(S.size() != T.size()){
        cout << "No" << endl;
        return 0;
    }

    int n = S.size(), ng = 0;
    for(int  i=0; i<n; i++){
        if(S[i].first != T[i].first) ng=1;
        if(S[i].first == T[i].first){
            if(S[i].second > T[i].second) ng=1;
            if(S[i].second > 1 && T[i].second == 1) ng=1;
            if(S[i].second == 1 && T[i].second > 1) ng=1;
        }
        if(ng) break;
    }
    if(ng) cout << "No" << endl;
    else cout << "Yes" << endl;

    rep(i, hoge.size()){
        cout << hoge[i] << endl;
    }

    return 0;
} 