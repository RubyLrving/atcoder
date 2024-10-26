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
    vector<P> LR(N);
    for(auto &lr:LR) cin >> lr.first >> lr.second;

    sort(LR.begin(), LR.end(), [](auto &x, auto &y){
        return get<0>(x) == get<0>(y)? get<1>(x) < get<1>(y): get<0>(x) < get<0>(y);
    });

    vector<P> DP;
    for(auto lr:LR){
        if(DP.size() == 0){
            DP.push_back(lr);
        }else{
            int ok=1;
            for(int i=0; i<DP.size(); i++){
                if(DP[i].first < lr.second && DP[i].second >= lr.first){
                    if(DP[i].first > lr.first){
                        DP[i].first = lr.first;
                    }
                    if(DP[i].second < lr.second){
                        DP[i].second = lr.second;
                    }  
                    ok = 0;                  
                }
            }
            if(ok){
                DP.push_back(lr);
            }
        }
    }
    for(auto lr:DP){
        cout << lr.first << ' ' << lr.second << endl;
    }

    return 0;
} 