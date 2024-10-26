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
 
bool dp[100000];
set<int> ret;
 
void divisor(int n) {
    int m=n, l=2;
    while(l*l<=m){
        if(m%l==0){
            ret.insert(l);
            m=m/l;
        }else{
            l++;
        }
    }
    ret.insert(m);
}
 
int main() {
    ll N, M;
    cin >> N >> M;
 
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
 
    for(int i=0; i<N; i++){
        if(A[i]==1) continue;
        divisor(A[i]);
    }

    for(auto& itr:ret){
        for(int i=itr; i<=M; i+=itr){
            dp[i] = true;
        }
    }

    vector<int> res;
    for(int i=1; i<=M; i++){
        if(dp[i]) continue;
        res.push_back(i);
    }
    sort(res.begin(), res.end());
 
    cout << res.size() << endl;
    rep(i, res.size()) cout << res[i] << endl; 
 
    return 0;
}