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

class Node{
public:
    ll value_=0;
    vector<int> child_;
    Node(){}
};

vector<Node> tree;
 
void dfs(int p, int praent, ll x){
    tree[p].value_ += x;
    for(int i=0; i<tree[p].child_.size(); i++){
        if(tree[p].child_[i] != praent) dfs(tree[p].child_[i], p, tree[p].value_);
    }
}

int main(int argc, const char * argv[]) {
    int n, q;
    cin >> n >> q;
    tree.resize(n, Node());
    
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].child_.push_back(b);
        tree[b].child_.push_back(a);
    }
    
    for(int i=0; i<q; i++){
        int p, x;
        cin >> p >> x;
        p--;
        tree[p].value_ += x;
    }
    
    dfs(0, 0, 0);
    
    for(int i=0; i<n; i++){
        if(i<n-1) cout << tree[i].value_ << ' ';
        else cout << tree[i].value_ << endl;
    }
}