#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> pigeon(N);
    map<int, int> mp;
    rep(i, N){
        pigeon[i] = i;
        mp[i]=1;
    }

    int ans = 0;
    
    rep(i, Q){
        int q;
        cin >> q;

        //cout << q << ' ';

        if(q == 1){
            int p, h;
            cin >> p >> h;
            //cout << p << ' ' << h;
            p--; h--;
            int m = pigeon[p];
            mp[m]--;
            if(mp[m] == 1) ans--;
            pigeon[p] = h;
            mp[h]++;
            if(mp[h] == 2) ans++;
        }

        if(q == 2){
            cout << ans << endl;
        }
        //cout << endl;
    }

    return 0;
} 
