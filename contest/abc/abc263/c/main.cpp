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

int N, M;
set<vector<int>> st;

void dfs(vector<int> v){
    if(v.size() == N){
        st.insert(v);
        return;
    }

    int i = 1;
    if(v.size()) i = v[v.size()-1] + 1;

    for(; i<=M; i++){
        v.push_back(i);
        dfs(v);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M;

    dfs(vector<int>());

    for(vector<int> s:st){
        for(auto v:s){
            cout << v << ' ';
        }
        cout << endl;
    }

    return 0;
} 