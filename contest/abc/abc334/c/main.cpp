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
    int N, M;
    cin >> N >> M;
    vector<ll> A(M), socks(N, 2);
    for(int i=0; i<M; i++){
        cin >> A[i];
        A[i]--;
        socks[A[i]]--;
    }
    vector<ll> x;
    for(int i=0; i<N; i++) for(int j=0; j<socks[i]; j++) x.push_back(i);

    int n = x.size();

    if(n % 2 == 0){
        ll ans = 0;
        for(int i=0; i<n/2; i++) ans += x[i*2+1] -  x[i*2];
        cout << ans << endl;
    }else{
        ll now = 0;
        for(int i=0; i<n/2; i++) now += x[i*2+2] -  x[i*2+1];
        ll ans = now;
        for(int i=2; i<n; i+=2){
            now += x[i-1] - x[i-2];
            now -= x[i] - x[i-1];
            ans = min(ans, now);
        }
        cout << ans << endl;
    }

    return 0;
} 