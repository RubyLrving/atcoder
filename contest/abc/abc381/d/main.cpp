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
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    
    int ans = 0;
    for(int i=0; i<2; i++){
        int right = i;
        set<int> st;
        for(int left = i; left < N; left+=2){
            while(right + 1 < N && A[right] == A[right+1] && st.find(A[right]) == st.end()){
                st.insert(A[right]);
                right += 2;   
            }
            ans = max(ans, right - left);
            if(right <= left) right = left + 2;
            if(st.find(A[left]) != st.end()) st.erase(A[left]);
        }
    }
    cout << ans << endl;

    return 0;
} 
