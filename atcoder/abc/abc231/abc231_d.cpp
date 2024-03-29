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
 
class UnionFind{
    vector<int> par_;
public:
    UnionFind(int n):par_(n){
        rep(i, n) par_[i] = -1;
    }
 
    int root(int x){
        if(par_[x] < 0) return x;
        return par_[x] = root(par_[x]);
    }
 
    bool unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
 
        if(rx == ry) return false;
        if (par_[rx] > par_[ry]) swap(rx, ry);
        par_[rx] += par_[ry];
        par_[ry] = rx;
        return true;
    }
 
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
 
    int size(int x){
        return -par_[root(x)];
    }
};
 
int main() {
    int N, M;
    cin >> N >> M;
 
    UnionFind uni(N);
    vector<int> g(N);
    int ok=1;
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a]++;
        g[b]++;
        if(uni.same(a, b) == false){
            uni.unite(a, b);
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
 
    rep(i, g.size()){
        if(g[i]>2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
 
    return 0;
}