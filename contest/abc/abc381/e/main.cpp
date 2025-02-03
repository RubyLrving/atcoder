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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> one(N), two(N), sum(N), total(N+1);
    if(S[0] == '1') one[0] = 1;
    repx(i, 1, N){
        if(S[i] == '1') one[i] = 1 + one[i-1];
        else one[i] = 0;
    }

    if(S[N-1] == '2') two[N-1] = 1;
    for(int i = N-2; i>=0; i--){
        if(S[i] == '2') two[i] = 1 + two[i+1];
        else two[i] = 0;
    }

    rep(i, N){
        if(S[i] == '/' && i-1>=0 && i+1<N){
            int len = min(one[i-1], two[i+1]);
            if((len * 2 + 1) % 2 == 1) sum[i] = len * 2 + 1;
        }
    }
    rep(i, N) total[i+1] = sum[i] + total[i];

    rep(i, Q){
        int l, r;
        cin >> l >> r;
        cout << total[r] - total[l] << endl;
    }
    

    return 0;
} 
