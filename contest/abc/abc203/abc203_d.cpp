#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
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
    int N, K;
    cin >> N >> K;

    int A[801][801];
    rep(i, N) rep(j, N){
        cin >> A[i][j];
    }

    ll res=1000000007;
    ll cnt = (K*K)/2;
    rep(i, N-K+1) rep(j, N-K+1){   
        vector<ll> p;     
        for(int ik=0; ik<K; ik++){
            for(int jk=0; jk<K; jk++){
                p.push_back(A[i+ik][j+jk]);
            }
        }
        sort(p.begin(), p.end(), [](auto const& x, auto const& y)->int{
            return (x>y);
        });
        res = min(res, p[cnt]);
    }
    cout << res << endl;

    return 0;
}