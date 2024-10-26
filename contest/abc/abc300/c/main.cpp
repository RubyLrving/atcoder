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

int CrossMark(int y, int x, int H, int W, vector<string> C){
    int N = min(H, W);
    int n = 0;

    for(int d=1; d+d+1<=N; d++){

        if(y+d>=H || x+d>=W || y-d<0 || x-d<0) continue;

        if(C[y+d][x+d] == '#' && C[y+d][x-d] == '#' && C[y-d][x+d] == '#' && C[y-d][x-d] == '#'){
            n++;
        }else{
            break;
        }
    }

    return n;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    rep(i, H) cin >> C[i];

    map<int, int> mp;
    for(int i=1; i <= min(H,W); i++) mp[i] = 0;
    for(int y=1; y<H-1; y++){
        for(int x=1; x<W-1; x++){
            if(C[y][x] == '#'){
                int n = CrossMark(y, x, H, W, C);
                mp[n]++;
            }
        }
    }
    int cnt = 0;
    for(auto m:mp){
        if(m.first > 0){
            cout << m.second;
            (cnt < mp.size() - 1)? cout << ' ':cout << endl;
        }
        cnt++;
    }

    return 0;
} 