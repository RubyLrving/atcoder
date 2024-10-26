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
    int W, B;
    cin >> W >> B;
    if(W == 0 && B == 0){
        cout << "Yes" << endl;
        return 0;
    }

    string S;
    rep(i, 240/12) S += "wbwbwwbwbwbw";
    vector<P> CumulativeSum(250);

    rep(i, 240){
        CumulativeSum[i+1].first = CumulativeSum[i].first;
        CumulativeSum[i+1].second = CumulativeSum[i].second;
        if(S[i] == 'w'){
            CumulativeSum[i+1].first += 1;
        }else{
            CumulativeSum[i+1].second += 1;
        }
    }

    for(int i=0; i<=240; i++){
        for(int j=i+1; j<=240; j++){
            int w = CumulativeSum[j].first - CumulativeSum[i].first;
            int b = CumulativeSum[j].second - CumulativeSum[i].second;
            if(w == W && b == B){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
} 