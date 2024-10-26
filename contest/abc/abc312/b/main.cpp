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

string TakCode[9] = { 
    {"###.?????"},
    {"###.?????"},
    {"###.?????"},
    {"....?????"},
    {"?????????"},
    {"?????...."},
    {"?????.###"},
    {"?????.###"},
    {"?????.###"},
};

bool CheckTakCode(vector<string> graph, int h, int w){
    for(int y = 0; y<9; y++){
        for(int x = 0; x<9; x++){
            if(TakCode[y][x] == '?') continue;

            if(graph[h+y][w+x] != TakCode[y][x]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    int ok = 0;
    for(int i=0; i<N-8; i++){
        for(int j=0; j<M-8; j++){
            if(CheckTakCode(S, i, j)){
                cout << i+1 << ' ' << j+1 << endl;
                ok = 1;
            }
        }
    }
    if(!ok) cout << endl;

    return 0;
} 