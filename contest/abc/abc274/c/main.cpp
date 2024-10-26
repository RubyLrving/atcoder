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
    ll N;
    cin >> N;
    vector<P> A;
    rep(i, N){
        int a;
        cin >> a;
        A.push_back(P(i+1, a));
    }
    ll max_ameba = 2*N + 1;
    vector<ll> amebas(max_ameba+1, -1);
    amebas[1] = 0;
    for(ll i=1; i<=N; i++){
        int index = A[i-1].first;
        int parent = A[i-1].second;
        if(amebas[2*index] == -1) amebas[2*index] = amebas[parent] + 1;
        if(amebas[2*index+1] == -1) amebas[2*index+1] = amebas[parent] + 1;
    }

    for(ll i=1; i<=max_ameba; i++){
        cout << amebas[i] << endl;
    }

    return 0;
} 