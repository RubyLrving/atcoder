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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<P> p(N);
    rep(i, N){
        int success = 0;
        rep(j, N) if(S[i][j] == 'o') success++;
        
        p[i].first = success;
        p[i].second = i+1;
    }

    //sort
    sort(p.begin(), p.end(), [](P const& x, P const& y){
        return x.first == y.first? x.second < y.second: x.first > y.first;
    });

    rep(i, N){
        cout << p[i].second << ' ';
    }

    return 0;
} 