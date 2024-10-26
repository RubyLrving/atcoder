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

    vector<string> A(2*N);
    vector<P> res(2*N);
    rep(i, 2*N){
        cin >> A[i];
        res[i].first = i;
    }

    rep(m, M){
        for(int i=0; i<2*N; i+=2){
            if(A[res[i].first][m] == 'G' && A[res[i+1].first][m] == 'C') res[i].second++;
            if(A[res[i].first][m] == 'C' && A[res[i+1].first][m] == 'P') res[i].second++;
            if(A[res[i].first][m] == 'P' && A[res[i+1].first][m] == 'G') res[i].second++;
            if(A[res[i].first][m] == 'P' && A[res[i+1].first][m] == 'C') res[i+1].second++;
            if(A[res[i].first][m] == 'G' && A[res[i+1].first][m] == 'P') res[i+1].second++;
            if(A[res[i].first][m] == 'C' && A[res[i+1].first][m] == 'G') res[i+1].second++;
        }

        sort(res.begin(), res.end(), [](const auto &x, const auto &y)
        {
            return get<1>( x ) == get<1>( y ) ? get<0>( x ) < get<0>( y ) : get<1>( x ) > get<1>( y );
        });
    }

    rep(i, 2*N){
        cout << res[i].first + 1 << endl;
    }

    return 0;
}