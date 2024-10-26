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
    int H, W, rs, cs;
    cin >> H >> W >> rs >> cs;
    int N;
    cin >> N;
    map<int, vector<int>> mpx, mpy;
    rep(i, N){
        int r, c;
        cin >> r >> c;
        mpx[r].push_back(c);
        mpy[c].push_back(r);
    }
    for(auto& m:mpx) sort(m.second.begin(), m.second.end());
    for(auto& m:mpy) sort(m.second.begin(), m.second.end());
 
    int Q;
    cin >> Q;
    char d;
    int l;
    rep(i, Q){
        cin >> d >> l;
        if(d=='L'){
            int dl = 0;
            auto it = mpx.find(rs);
            if(it != mpx.end()){
                auto itr = lower_bound(it->second.begin(), it->second.end(), cs);
                if(itr != mpx[rs].begin()) itr--, dl = (*itr);
            }
            cs = max(cs-l, dl+1);
        }
        if(d=='R'){
            int dl = W+1;
            auto it = mpx.find(rs);
            if(it != mpx.end()){
                auto itr = upper_bound(it->second.begin(), it->second.end(), cs);
                if(itr != mpx[rs].end()) dl = (*itr);
            }
            cs = min(cs+l, dl-1);
        }
        if(d=='U'){
            int dl = 0;
            auto it = mpy.find(cs);
            if(it != mpy.end()){
                auto itr = lower_bound(it->second.begin(), it->second.end(), rs);
                if(itr != mpy[cs].begin()) itr--, dl = (*itr);
            }
            rs = max(rs-l, dl+1);
        }
        if(d=='D'){
            int dl = H+1;
            auto it = mpy.find(cs);
            if(it != mpy.end()){
                auto itr = upper_bound(it->second.begin(), it->second.end(), rs);
                if(itr != mpy[cs].end()) dl = (*itr);
            }
            rs = min(rs+l, dl-1);
        }
        cout << rs << ' ' << cs << endl;
    }
    return 0;
} 