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
    int N, Q;
    cin >> N >> Q;
    vector<string> P(N);
    rep(i, N) cin >> P[i];

    // 二次元累積和
    vector<vector<int> > s(N+1, vector<int>(N+1, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + (P[i][j] == 'B'?1:0);

    rep(i, Q){
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        int ans=0;
        int X1 = x1 % N;
        int X2 = x2 % N;
        int Y1 = min((y1+x1),N+1);
        int Y2 = min((y2+x2),N+1);
        ans += s[X2][Y2] - s[X1][Y2] - s[X2][Y1] + s[X1][Y1];

        
        cout << ans << endl;
    }

    return 0;
} 