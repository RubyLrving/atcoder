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
    ll N, M;
    cin >> N >> M;

    vector<P> A(M);
    rep(i, M){
        int a;
        cin >> a;
        A[i].first = a;
        A[i].second = i;
    }

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    ll total = 0;
    vector<ll> point(N, 0);
    rep(i, N){ 
        rep(j, M) if(S[i][j] == 'o') point[i] += A[j].first;
        point[i] += i + 1;
        total += point[i];
    }

        //sort
    sort(A.begin(), A.end(), [](P const& x, P const& y){
        return x.first == y.first? x.second < y.second: x.first > y.first;
    });

    rep(i, N){
        ll top = 0;
        rep(k, N) if(i!=k) top = max(top, point[k]);

        if(top < point[i]){
            cout << 0 << endl;
            continue;
        }

        ll p = point[i];
        ll cnt = 0;
        rep(j, M){
            if(S[i][A[j].second] == 'x'){
                p += A[j].first;
                cnt++;
            }
            if(top <= p){
                cout << cnt << endl;
                break;
            }
        }
    }

    return 0;
} 