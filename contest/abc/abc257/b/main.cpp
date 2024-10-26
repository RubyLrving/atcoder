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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(K+1), L(Q);
    for(int i=1;i<=K; i++) cin >> A[i];
    for(auto &l:L) cin >> l;
    for(auto &l:L){
        if(A[l] == N) continue;
        else if(l == K) A[l]++;
        else if(A[l]+1 < A[l+1]) A[l]++;
    }
    for(int i=1; i<=K; i++){
        cout << A[i];
        if(i<K) cout << ' ';
        else cout << endl;
    }
    return 0;
} 