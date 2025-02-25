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
    int N = 8, K = 0;
    string S;
    cin >> S;
    vector<int> B(2), R;
    rep(i, N){
        if(S[i] == 'B') B[(i+1)%2]++;
        if(S[i] == 'R') R.push_back(i+1);
        if(S[i] == 'K') K = i+1;
    }

    if(B[0] == 1 && B[1] == 1 && R[0] < K && K < R[1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
} 