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
    int H, W;
    cin >> H >> W;
    vector<string> S(H), T(H);
    rep(i, H) cin >> S[i];
    rep(i, H) cin >> T[i];

    map<string, int> SS, ST;
    rep(i, W){
        string tempS, tempT;
        rep(j, H){
            tempS += S[j][i];
            tempT += T[j][i];
        }
        SS[tempS]++;
        ST[tempT]++;        
    }

    if(SS.size() != ST.size()){
        cout << "No" << endl;
        return 0;
    }

    int n = SS.size();
    int res = 1;
    auto itrS = SS.begin();
    auto itrT = ST.begin();    
    rep(i, n){
        if(!(itrS->first == itrT->first && itrS->second == itrT->second)){
            res = 0;
        }
        itrS++;
        itrT++;
    }
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 