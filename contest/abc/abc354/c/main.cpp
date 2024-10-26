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
    vector<tuple<int, int, int>> AC;

    rep(i, N){
        int a, c;
        cin >> a >> c;
        AC[i] = make_tuple(a, c, i+1);
    }

    sort(AC.begin(), AC.end(), [](auto const& x, auto const& y){
        return get<0>(x) >  get<0>(y);
    });

    vector<int> ans;
    int min_cost = 1000000000;
    for(auto a:AC){
        int cost = get<1>(a);
        if(cost < min_cost){
            ans.push_back(get<2>(a));
            min_cost = cost;
        }
    }

    cout << ans.size() << endl;
    for(auto a:ans){
        cout << a << ' ';
    }

    return 0;
} 