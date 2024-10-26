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

ll N;
ll graph[16][16];
bool used[16];
vector<pair<int, int>> vec;
ll res;

void dfs(){

    if(vec.size()==N){
        ll ans=0;
        for(auto v:vec){
            ans^=graph[v.first][v.second];
        }
        res = max(res, ans);
        return;
    }

    int l;
    rep(i, 2*N){
        if(!used[i]){
            l=i;
            break;
        }
    }

    used[l] = true;
    repx(i, 1, 2*N){
        if(!used[i]){
            vec.push_back(P(l, i));
            used[i] = true;
            dfs();
            used[i] = false;
            vec.pop_back();
        }
    }
    used[l] = false;
}

int main() {
    
    cin >> N;
    vector<int> parson(2*N);
    rep(i, 2*N) parson[i]=0;

    rep(i, 2*N-1){
        repx(j, i+1, 2*N){
            cin >> graph[i][j];
        }
    }
    dfs();
    cout << res << endl;

    return 0;
} 