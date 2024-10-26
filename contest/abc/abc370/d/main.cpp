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
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<set<int>> h(H), w(W);
    rep(i, H){
        rep(j, W){
            h[i].insert(j);
            w[j].insert(i);
        }
    }

    auto erase = [&](int i, int j){
        h[i].erase(j);
        w[j].erase(i);
    };

    for(int i=0; i<Q; i++){
        int r, c;
        cin >> r >> c;
        r--; c--;

        if(h[r].count(c)){
            h[r].erase(c);
            w[c].erase(r);
            continue;
        }

        {
            auto itr = h[r].lower_bound(c);
            if(itr != h[r].begin()) erase(r, *prev(itr));
        }

        {
            auto itr = h[r].lower_bound(c);
            if(itr != h[r].end()) erase(r, *itr);
        }

        {
            auto itr = w[c].lower_bound(r);
            if(itr != w[c].begin()) erase(*prev(itr), c);
        }

        {
            auto itr = w[c].lower_bound(r);
            if(itr != w[c].end()) erase(*itr, c);
        }
    }

    int ans = 0;
    for(int i=0; i<H; i++) ans += h[i].size();
    cout << ans << endl;

    return 0;
} 