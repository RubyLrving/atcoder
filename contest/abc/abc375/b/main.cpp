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
    vector<pair<double, double>> P(N+2, {0.0, 0.0});
    rep(i, N) cin >> P[i+1].first >> P[i+1].second;

    double ans = 0.0;
    for(int i=1; i<N+2; i++){
        auto dist = [](const pair<double, double>& p1, const pair<double, double>& p2) -> double {
            return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
        };
        ans += dist(P[i], P[i-1]);
    }
    cout << fixed << setprecision(6) << ans << endl;
    
    return 0;
} 