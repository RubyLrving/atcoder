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
    int H1, W1, H2, W2;
    int A[15][15];
    int B[15][15];
    cin >> H1 >> W1;
    for(int i=1; i<=H1; i++) for(int j=1; j<=W1; j++) cin >> A[i][j];

    cin >> H2 >> W2;
    for(int i=1; i<=H2; i++) for(int j=1; j<=W2; j++) cin >> B[i][j];

    for(int i=0; i<(1<<H1); i++){
        for(int j=0; j<(1<<W1); j++){

            vector<int> hvec, wvec;
            for(int k = 1; k <= H1; k++) if((i & (1<<(k-1))) == 0) hvec.push_back(k);
            for(int k = 1; k <= W1; k++) if((j & (1<<(k-1))) == 0) wvec.push_back(k);
            if(hvec.size() != H2 || wvec.size() != W2) continue;

            bool ok=true;
            for(int k=1; k<=H2; k++){
                for(int l=1; l<=W2; l++){
                    if(A[hvec[k-1]][wvec[l-1]] != B[k][l]){
                        ok = false;
                    }
                }
            }
            if(ok){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
 
    return 0;
} 