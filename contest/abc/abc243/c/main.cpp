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

    map<int, vector<P>> mp;
    rep(i, N){
        P p;
        int y;
        cin >> p.first >> y;
        p.second = i;
        mp[y].push_back(p);
    }
    
    string s;
    cin >> s;
    int ok=0;
    for(auto m:mp){
        vector<P> v = m.second;
        if(v.size()<2) continue;

        sort(v.begin(), v.end());

        char l = ' ';
        for(auto vv:v){
            if(s[vv.second] == 'R') l = 'R';
            if(l == 'R' && s[vv.second] == 'L') ok = 1;
        }
        if(ok) break;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 