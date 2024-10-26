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
using P = pair<ll,ll>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int Q;
    cin >> Q;
    deque<P> dqu;

    rep(i, Q){
        int type;
        cin >> type;

        if(type == 1){
            int x, c;
            cin >> x >> c;
            dqu.push_back(P(x, c));

        }else{
            int c;
            cin >> c;

            ll ans=0;
            while(c){
                P p = dqu.front();
                if(p.second <= c){
                    c -= p.second;
                    ans += p.second * p.first;
                    dqu.pop_front();
                }else{
                    ans += c * p.first;
                    p.second -= c;
                    c = 0;
                    dqu.pop_front();
                    dqu.push_front(P(p.first, p.second));
                }
            }
            cout << ans << endl;
        }
    }


    return 0;
} 