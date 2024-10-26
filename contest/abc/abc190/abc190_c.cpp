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
    int n, m;
    cin >> n >> m;

    vector<int> A(m), B(m);
    rep(i, m) cin >> A[i] >> B[i];

    int k;
    cin >> k;

    vector<int> C(k), D(k);
    rep(i, k) cin >> C[i] >> D[i];

    int res=0;
    for(int bit=0; bit<(1<<k); bit++){

        vector<int> ball(n+1);
        for(int i=0; i<k; i++){
            if(bit>>i&1){
                ball[D[i]]++;
            }else{
                ball[C[i]]++;
            }
        }

        int total=0;
        for(int i=0; i<m; i++){
            if(ball[A[i]]>0 && ball[B[i]]>0) total++;
        }
        res = max(res, total);
    }
    cout << res << endl;

    return 0;
}