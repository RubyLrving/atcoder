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
    ll N;
    cin >> N;
    vector<ll> L(N), R(N);
    ll LSUM = 0;
    rep(i, N){
        cin >> L[i] >> R[i];
        LSUM += L[i];
    }

    vector<ll> ans(N);
    rep(i, N){
        if(LSUM == 0){
            break;
        }
        if(LSUM > 0){
            ll diff = min(LSUM, L[i] - R[i]);
            ans[i] = L[i] - diff;
            LSUM -= diff;
        }
        if(LSUM < 0){
            ll diff = min(-LSUM, R[i] - L[i]);
            L[i] = L[i] + diff;
            LSUM += diff;
        }
    }

    if(LSUM == 0){
        cout << "Yes" << endl;
        for(int i=0; i<N; i++){
            cout << L[i];
            if(i<N-1){
                cout << ' ';
            }else{
                cout << endl;
            }
        }
    }else{
        cout << "No" << endl;
    }

    return 0;
} 