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
    set<int> A, B;
    int n, m;
    cin >> n >> m;

    rep(i, n){
        int a;
        cin >> a;
        A.insert(a);
    }

    rep(i, m){
        int b;
        cin >> b;
        B.insert(b);
    }

    set<int> t_union, t_intersection, res;
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(t_union, t_union.begin()));
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(t_intersection, t_intersection.begin()));
    set_difference(t_union.begin(), t_union.end(), t_intersection.begin(), t_intersection.end(), inserter(res, res.begin()));

    for(auto &itr:res){
        cout << itr << ' ';
    }

    return 0;
}