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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    int H, W;
    ll X;
    cin >> H >> W >> X;
    int P, Q;
    cin >> P >> Q;
    P--; Q--;
    vector<vector<ll>> S(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> S[i][j];

    ll total = S[P][Q];
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<int>> pque;
    pque.emplace(0, Q, P);
    
    vector<vector<bool>> used(H, vector<bool>(W, false));
    used[P][Q] = true;
    
    while(pque.size()){
        const auto [size, x, y] = pque.top();
        pque.pop();

        if(size >= (total + X - 1) / X){
            break;
        }

        total += size;

        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx<0 || W<=xx || yy<0 || H<=yy) continue;

            if(used[yy][xx] == false){
                used[yy][xx] = true;
                pque.emplace(S[yy][xx], xx, yy);
            }
        }
    }
    cout << total << endl;

    return 0;
} 
