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
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<vector<int>> h(W), w(H);
    rep(i, H) w[i].push_back(-1);
    rep(i, W) h[i].push_back(-1);
    rep(i, H) rep(j, W){
        if(S[i][j] == '#'){
            h[j].push_back(i);
            w[i].push_back(j);
        }
    }
    rep(i, H) w[i].push_back(W);
    rep(i, W) h[i].push_back(H);

    int ans = 0;
    rep(i, H) rep(j, W){

        if(S[i][j] == '#') continue;

        int sum = 0;
        int index = lower_bound(w[i].begin(), w[i].end(), j) - w[i].begin();
        int x1 = w[i][index-1];
        int x2 = w[i][index];
        
        sum += j - (x1 + 1);
        sum += x2 - j;

        index = lower_bound(h[j].begin(), h[j].end(), i) - h[j].begin();
        int y1 = h[j][index-1];
        int y2 = h[j][index];

        sum += i - (y1 + 1);
        sum += y2 - i;

        sum--;

        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
} 