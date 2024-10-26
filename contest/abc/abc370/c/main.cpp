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
    string S, T;
    cin >> S >> T;

    vector<string> ans;
    while(S != T){
        vector<string> A;
        for(int i=0; i<S.size(); i++){
            string C = S;
            if(C[i] != T[i]){
                C[i] = T[i];
                A.push_back(C);
            }
        }
        sort(A.begin(), A.end());
        ans.push_back(A[0]);
        S = A[0];
    }

    cout << ans.size() << endl;
    for(auto a:ans){
        cout << a << endl;
    }

    return 0;
} 