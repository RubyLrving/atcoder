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
    int N, M;
    cin >> N >> M;

    vector<queue<int>> A(M);
    vector<vector<int>> mem(N);
    queue<int> que;
    rep(i, M){
        int k;
        cin >> k;

        rep(j, k){
            int a;
            cin >> a;
            A[i].push(a-1);
        }
        mem[A[i].front()].push_back(i);
    }

    rep(i, N){
        if(mem[i].size() == 2){
            que.push(i);
        }
    }

    while(que.size()>0){
        int now = que.front();
        que.pop();

        for(auto &v:mem[now]){
            A[v].pop();
            if(!A[v].empty()){
                mem[A[v].front()].push_back(v);
                if(mem[A[v].front()].size() == 2){
                    que.push(A[v].front());
                }
            } 
        }
    }

    int ok = 1;
    for(auto &v:A){
        if(!v.empty()) ok = 0;
    }
    if(ok) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}