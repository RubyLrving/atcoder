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
    int h[3], w[3];
    rep(i, 3) cin >> h[i];
    rep(i, 3) cin >> w[i];

    ll ans=0;
    repx(m1, 1, 29){
        repx(m2, 1, 29){
            repx(m3, 1, 29){
                if(m1 + m2 + m3 != w[0]) continue;
                repx(m4, 1, 29){
                    repx(m5, 1, 29){
                        repx(m6, 1, 29){
                        if(m4 + m5 + m6 != w[1]) continue;
                            repx(m7, 1, 29){
                                if(m1 + m4 + m7 != h[0]) continue;
                                repx(m8, 1, 29){
                                    if(m2 + m5 + m8 != h[1]) continue;
                                    repx(m9, 1, 29){
                                        if(m7 + m8 + m9 != w[2]) continue;
                                        if(m3 + m6 + m9 != h[2]) continue;
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
} 