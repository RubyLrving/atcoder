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
using P = pair<ll,ll>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

ll dx[4] = {1, 1, -1, -1};
ll dy[4] = {1, -1, 1, -1};

ll graph[401][401];

int main() {
    ll N, M;
    cin >> N >> M;

    vector<P> dict;
    for(ll x=0; x*x<=M; x++){
        for(ll y=0; x*x + y*y<=M; y++){
            if(x*x+y*y == M){
                dict.push_back(P(x, y));
            }
        }
    }

    repx(i, 1, N+1) repx(j, 1, N+1) graph[i][j] = -1;
    queue<P> que;
    que.push(P(1, 1));
    graph[1][1] = 0;

    while(que.size()){
        P p = que.front();
        que.pop();

        for(auto d:dict){
            for(int i=0; i<4; i++){
                ll k = p.first + d.first * dx[i];
                ll l = p.second + d.second * dy[i];

                if(k<1 || N<k || l<1 || N<l) continue;
                if(graph[k][l] > -1) continue;
                graph[k][l] = graph[p.first][p.second] + 1;
                que.push(P(k, l));
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << graph[i][j];
            if(j<N) cout << ' ';
        }
        cout << endl;
    }

    return 0;
} 