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
    int N, D;
    cin >> N >> D;

    vector<int> L(N), R(N);
    rep(i, N){
        cin >> L[i] >> R[i];
    }

    int cnt=0;
    while(L.size()){
        vector<P> T;
        rep(i, L.size()){
            T.push_back(P(L[i], 1));
            T.push_back(P(R[i]+1, -1));
        }
        sort(T.begin(), T.end());
        int sum=0;
        int res=0;
        int p = 0;
        for(auto t:T){
            sum += t.second;
            res = max(sum, res);
            if(sum>=res) p = t.first;
        }
        for(int i=L.size()-1; i>=0; i--){
            if(p <= R[i]+D-1 && L[i]<= p+D-1){
                L.erase(L.begin()+i);
                R.erase(R.begin()+i);
            }
        }
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}