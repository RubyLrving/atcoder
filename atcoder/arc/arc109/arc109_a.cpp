#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int dx[8] = { 0,  1, -1, 1, -1, 0};
int dy[8] = {-1, -1,  0, 0,  1, 1};
int feild[100][2];

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    a--;
    b--;
    queue<P> que;
    que.push(P(a, 0));

    while(que.size()){
        P p = que.front();
        que.pop();

        for(int i=0; i<8; i++){
            int dxx = dx[i] + p.second;
            int dyy = dy[i] + p.first;

            if(dxx<0 || 2<=dxx || dyy<0 || 100<=dyy) continue;
            int cost = 0;
            if(dx[i]==0) cost = y;
            else cost = x;

            if(feild[p.first][p.second] + cost < feild[dyy][dxx] || feild[dyy][dxx]==0){
                feild[dyy][dxx] = feild[p.first][p.second] + cost;
                que.push(P(dyy, dxx));
            }
        }
    }
    cout << feild[b][1] << endl;
    return 0;
}