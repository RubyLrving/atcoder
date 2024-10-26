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
    int N, D;
    cin >> N >> D;
    vector<P> users(N);
    rep(i, N){
        int x, y;
        cin >> x >> y;
        users[i] = P(x, y);
    }

    vector<bool> used(N, false);
    queue<P> que;
    que.push(users[0]);
    used[0] = true;
    while(que.size()){
        P p = que.front();
        que.pop();

        rep(i, N){
            if(used[i]) continue;

            int x = p.first - users[i].first;
            int y = p.second - users[i].second;  

            if(x * x + y * y <= D * D){
                used[i] = true;
                que.push(users[i]);
            }
        }
    }

    rep(i, N){
        if(used[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
} 