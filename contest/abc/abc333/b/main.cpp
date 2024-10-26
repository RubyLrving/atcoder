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

int Pentagon[5][5] = {{0, 1, 2, 2, 1}, {1, 0, 1, 2, 2}, {2, 1, 0, 1, 2}, {2, 2, 1, 0, 1}, {1, 2, 2, 1, 0}};

int main() {

    string S, T;
    cin >> S >> T;

    int s1 = S[0] - 'A';
    int s2 = S[1] - 'A';
    int t1 = T[0] - 'A';
    int t2 = T[1] - 'A';

    if(Pentagon[s1][s2] == Pentagon[t1][t2]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
} 