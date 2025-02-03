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
    int n = 5;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n){
        swap(a[i], a[i+1]);
        if(a == vector<int>({1, 2, 3, 4, 5})){
            cout << "Yes"<< endl;
            return 0;
        }
        swap(a[i], a[i+1]);
    }
    cout << "No" << endl;
    return 0;
} 
