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

vector<int> ans;
vector<bool> seen, finished;
vector<vector<int>> graph;
bool is_detect = false;

void dfs(int p){

    if(is_detect) return;

    seen[p] = true;
    ans.push_back(p);

    for(auto g:graph[p]){

        if(finished[g]) continue;

        if(seen[g]){
            if(!finished[g]){
                is_detect = true;
                ans.push_back(g);
            }
        }else{
            dfs(g);
        }
    }

    finished[p] = true;
    if(!is_detect) ans.pop_back();
}

int main() {
    int N;
    cin >> N;
    graph.resize(N);
    seen.resize(N);
    finished.resize(N);
    
    rep(i, N){
        int a;
        cin >> a;
        a--;
        graph[i].push_back(a);
    }

    for(int i=0; i<N; i++){
        dfs(i);
        if(is_detect){
            break;
        }
    }

    int n = ans.size()-1;
    int e = ans[n];
    int s = 0;
    for(int i=0; i<n; i++){
        if(e == ans[i]){
            s = i;
            break;
        }
    }

    cout << ans.size() - s - 1 << endl;
    for(int i=s; i<ans.size()-1; i++) cout << ans[i] + 1 << ' ';


    return 0;
} 