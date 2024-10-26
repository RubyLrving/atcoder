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

bool graph[101][101];

int main() {
    int N, M;
    cin >> N >> M;
    rep(i, M){
        int k;
        cin >> k;
        vector<int> x(k);
        rep(j, k) cin >> x[j];
        rep(p, k-1){
            repx(q, p+1, k){
                graph[x[p]][x[q]] = true;
                graph[x[q]][x[p]] = true;
            }
        }
    }

    bool ok = true;
    repx(p, 1, N+1){
        repx(q, p+1, N+1){
            if(graph[p][q] == false) ok = false;
        }
    }
    
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 