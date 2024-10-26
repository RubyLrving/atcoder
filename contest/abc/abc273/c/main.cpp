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
    int N;
    cin >> N;
    vector<int> A(N), AA;
    rep(i, N) cin >> A[i];
    set<int> st;
    rep(i, N) st.insert(A[i]);
    for(auto s:st) AA.push_back(s);
    map<int, int> mp;
    rep(i, N){
        int t = A[i];
        auto itr = upper_bound(AA.begin(), AA.end(), t);
        int r = AA.size() - distance(AA.begin(), itr);
        mp[r]++;
    }
    rep(i, N) cout << mp[i] << endl;
    return 0;
} 