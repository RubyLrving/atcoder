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
    int N;
    cin >> N;

    vector<pair<string, string>> ST(N);
    rep(i, N){
        cin >> ST[i].first >> ST[i].second;
    }

    int ok=0;
    rep(i, N){
        for(int j=i+1; j<N; j++){
            if(ST[i].first == ST[j].first && ST[i].second == ST[j].second) ok=1;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}