#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
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

int N = 1048576;
int A[1048586] = {-1};

int main() {

    rep(i, N) A[i] = -1;

    int Q;
    cin >> Q;

    vector<int> t(Q);
    vector<int> x(Q);
    rep(i, Q){
        ll X;
        cin >> t[i] >> X;
        x[i] = X % N;
    }

    rep(i, Q){
        if(t[i] == 1){
            int h = x[i];
            while(1){
                if(A[h%N] != -1) h++;
                else break;
            }
            A[h%N] = x[i];
        }else{
            int h = x[i];
            cout << A[h] << endl;
        }
    }

    return 0;
}