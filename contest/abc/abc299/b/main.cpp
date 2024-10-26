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
    int N, T;
    cin >> N >> T;
    vector<int> C(N), R(N);
    rep(i, N) cin >> C[i];
    rep(i, N) cin >> R[i];

    map<int, vector<P>> mp;
    rep(i, N) mp[C[i]].push_back(P(R[i], i+1));

    if(mp.find(T) != mp.end()){
        vector<P> v = mp[T];
        sort(v.begin(), v.end());
        cout << v[v.size()-1].second << endl;
    }else{
        vector<P> v = mp[C[0]];
        sort(v.begin(), v.end());
        cout << v[v.size()-1].second << endl;
    }

    return 0;
} 