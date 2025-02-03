#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, char>> xyc;
    rep(i, M){
        int x, y;
        char c;
        cin >> x >> y >> c;
        xyc.push_back(tuple<int, int, char>(x, y, c));
    }
    
    sort(xyc.begin(), xyc.end(), [](const tuple<int, int, char> x, const tuple<int, int, char> y){
        return get<0>(x) == get<0>(y)? get<1>(x) < get<1>(y) : get<0>(x) < get<0>(y);
    });

    int miny = 1 << 30;
    rep(i, M){
        if(get<2>(xyc[i]) == 'W'){
            miny = min(get<1>(xyc[i]), miny);
        }else{
            if(get<1>(xyc[i]) >= miny){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
} 
