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

int N;
int A[200];
vector<vector<ll>> AA;

void dfs(vector<ll> D, int n){
    if(N==n){
        AA.push_back(D);
        return;
    }
    dfs(D, n+1);
    D.push_back(A[n]);
    dfs(D, n+1);

}

int main() {
    cin >> N;
    rep(i, N) cin >> A[i];

    dfs(vector<ll>(), 0);

    ll res=0;
    for(int i=0; i<AA.size(); i++){
        for(int j=i+1; j<AA.size(); j++){
            ll s1= accumulate(AA[i].begin(), AA[i].end(), 0LL);
            ll s2= accumulate(AA[j].begin(), AA[j].end(), 0LL);
            if(s1%200==s2%200){
                cout << "Yes" << endl;
            }
        }
    }
    cout << res << endl;

    return 0;
}