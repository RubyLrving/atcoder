#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int K;
    cin >> K;
    string s, t;
    cin >> s >> t;
    int ns = s.size();
    int nt = t.size();

    if(abs(ns - nt) >= 2){
        cout << "No" << endl;
        return 0;
    }

    if(ns == nt){
        int cnt = 0;
        rep(i, ns){
            if(s[i] != t[i]) cnt++;
        }
        if(cnt >= 2){
            cout << "No" << endl;
            return 0;
        }
    }
    if(abs(ns - nt) == 1){
        if(ns > nt) swap(s, t); 
        int n = min(ns, nt);
        int cnt = 0;
        rep(i, n){
            while(s[i] != t[cnt]){
                cnt++;
                if(cnt-i > 1){
                    cout << "No" << endl;
                    return 0;
                }
            }
            cnt++;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
} 
