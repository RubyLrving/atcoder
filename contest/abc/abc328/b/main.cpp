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
    vector<int> D(N);
    rep(i, N) cin >> D[i];

    int ans=0;
    rep(i, N){
        rep(j, D[i]){
            set<int> st;
            int mon = (i + 1);
            int day = (j+1);

            while(mon>0){
                st.insert(mon%10);
                mon=mon/10;
            }

            while(day>0){
                st.insert(day%10);
                day=day/10;
            }

            if(st.size()==1) ans++;
        }
    }
    cout << ans << endl; 

    return 0;
} 