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

int dis[7] = {0, 3, 1, 4, 1, 5, 9};
string pos = "ABCDEFG";

int main() {
    char p, q;
    cin >> p >> q;

    map<char, int> mp;
    rep(i, 7){
        mp[pos[i]] = dis[i];
        if(i>0) mp[pos[i]] += mp[pos[i]-1];
    }

    if(p>q) swap(p, q);

    cout << abs(mp[p] - mp[q]) << endl;

    return 0;
} 