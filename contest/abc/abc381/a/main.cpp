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
    string S;
    cin >> S;

    auto No = [](){
        cout << "No" << endl;
        exit(0);
    };

    if(N%2 == 0) No();

    int ans = 0;
    repx(i, 1, N+1){
        if((N + 1) / 2 - 1 >= i && S[i-1] != '1') No();
        if((N + 1) / 2 == i && S[i-1] != '/') No();
        if((N + 1) / 2 + 1 <= i && S[i-1] != '2') No();
    }

    cout << "Yes" << endl;
    return 0;
} 
