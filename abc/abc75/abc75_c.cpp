#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

class UnionFind{
    vector<int> par_;

public:
    UnionFind(int N) : par_(N){
        rep(i, N) par_[i] = i;
    }

    int root(int x){
        if(par_[x] == x) return x;
        return par_[x] = root(par_[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);

        if(rx == ry) return;
        par_[rx] = ry;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;

    vector<P> v(m);
    rep(i, m){
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
    }

    int res=0;
    rep(i, m){
        UnionFind uni(n);
        rep(j, m){
            if(i != j && !uni.same(v[j].first, v[j].second)){
                uni.unite(v[j].first, v[j].second);
            }
        }
        set<int> s;
        rep(j, n){
            if(uni.root(j) == j) s.insert(j);
        }
        if(s.size()>1) res++;
    }
    cout << res << endl;
    return 0;
}