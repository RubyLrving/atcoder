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
    vector<string> s(N), t(N);
    map<string, int> mp;
    rep(i, N){
        cin >> s[i] >> t[i];
        mp[s[i]]++;
        mp[t[i]]++;
    }

    int ok=1;
    rep(i, N){
        if(s[i]==t[i]) mp[t[i]]-=1;
        if(!(mp[s[i]]==1 || mp[t[i]]==1)) ok=0;
        if(s[i]==t[i]) mp[t[i]]+=1;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 