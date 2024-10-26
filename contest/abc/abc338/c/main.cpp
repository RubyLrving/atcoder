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
    int N;
    cin >> N;
    vector<int> Q(N), A(N), B(N);
    rep(i, N) cin >> Q[i];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    int acnt = 1000000;
    rep(i, N){
        if(A[i]>0){
            if(Q[i] / A[i] > 0) acnt = min(acnt, Q[i] / A[i]);
            if(Q[i] < A[i]){
                acnt = 0;
                break;
            }
        }
    }

    int bcnt = 1000000;
    rep(i, N){
        if(B[i]>0){
            if(Q[i] / B[i] > 0) bcnt = min(bcnt, Q[i] / B[i]);
            if(Q[i] < B[i]){
                bcnt = 0;
                break;
            }
        }
    }

    if(acnt==0 || bcnt==0){
        cout << acnt + bcnt << endl;
        return 0;
    }

    int ans = 0;
    repx(i, 0, acnt+1){
        int bcnt = 1000000;
        rep(j, N){
            if(B[j]>0){
                int cost = Q[j] - A[j] * (acnt-i);
                if(cost / B[j] > 0) bcnt = min(bcnt, cost / B[j]);
                if(cost < B[j]){
                    bcnt = 0;
                    break;
                }
            }
        }
        ans = max(ans, (acnt-i) + bcnt);
    }
    cout << ans << endl;
    
    return 0;
} 