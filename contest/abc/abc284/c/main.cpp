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

struct UnionFind{
    vector<int> par, rank, siz;

    UnionFind(int N): par(N,-1), rank(N, 0), siz(N, 1){}

    int root(int x){
        if(par[x]==-1) return x;
        else return par[x] = root(par[x]);
    }

    bool isSame(int x, int y){
        return root(x) == root(y);
    }

    bool unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return false;
        if(rank[rx]<rank[ry]) swap(rx, ry);
        par[ry] = rx;
        if(rank[rx]==rank[ry]) rank[rx]++;
        siz[rx] += siz[ry];
        return true;
    }

    int size(int x){
        return siz[root(x)];
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uni(N);

    rep(i, M){
        int u, v;
        cin >> u >> v;

        if(uni.isSame(u, v) == false){
            uni.unite(u, v);
        }
    }

    map<int, int> mp;
    rep(i, N) mp[uni.size(i)]++;

    int ans=0;
    for(auto m:mp){
        ans += m.second / m.first;
    }
    cout << ans << endl;

    return 0;
} 