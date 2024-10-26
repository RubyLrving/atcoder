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

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N), C(N);
    vector<set<int>> F(N);
    rep(i, N){
        cin >> P[i] >> C[i];

        rep(j, C[i]){
            int f;
            cin >> f;
            F[i].insert(f);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j) continue;
            if( (F[i].size() < F[j].size() && P[i] >= P[j]) || (F[i] == F[j] && P[i] > P[j])){
                int ok = 1;
                
                for(auto f:F[i]) if(F[j].find(f) == F[j].end()) ok = 0;

                if(ok){
                    cout << "Yes" << endl;
                    return 0;
                }   
            }
        }
    }
    cout << "No" << endl;

    return 0;
} 