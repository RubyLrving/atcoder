#include <bits/stdc++.h>
#include <atcoder/all>
 
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
    ll Q;
    cin >> Q;

    queue<ll> que;
    ll time = 0;
    rep(i, Q){
        ll query;
        cin >> query;

        if(query == 1){
            que.push(time);
        }

        if(query == 2){
            ll T;
            cin >> T;
            time += T;
        }

        if(query == 3){
            ll H;
            cin >> H;
            ll cnt = 0;
            while(que.size() && time - que.front() >= H){
                que.pop();
                cnt++;
            }
            cout << cnt << endl;
        }
    }

    return 0;
} 