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

map<ll, ll> m;
 
ll BinarySearch(vector<ll> S, ll n, ll key){
 
    ll left = 0;
    ll right = n;
 
    while(left < right){
        ll mid = (right + left) / 2;
 
        if(S[mid] == key) return mid;
        else if(S[mid] > key) right = mid;
        else left = mid+1;
    }
 
    return left;
}
 
int main() {
    ll N, Q;
    cin >> N >> Q;
 
    vector<ll> A(N);
    for(ll i=0; i<N; i++) cin >> A[i];
 
    vector<ll> K(Q);
    for(ll i=0; i<Q; i++) cin >> K[i];
 
    for(ll i=0; i<Q; i++){
        ll index = BinarySearch(A, N, K[i]);
        if(index==-1){
            cout << K[i] << endl;
            continue;
        }
        while(index!=-1){
            if(m[K[i]+(index+1)]>0){
                ll t = m[K[i]+(index+1)];
                if(t==index) break;
                else index = t;
            }else{
                ll t = BinarySearch(A, N, K[i]+(index+1));
                m[K[i]+(index+1)] = t;
                if(t==index) break;
                else index = t;
            }
        }
        cout << K[i] + (index) << endl;
    }
 
    return 0;
}