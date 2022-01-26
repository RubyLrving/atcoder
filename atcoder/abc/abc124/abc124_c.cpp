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

int main() {
    string s;
    cin >> s;

    int sum1=0;
    int sum2=0;
    rep(i, s.size()){
        if(i%2==0){
            if(s[i] != '0') sum1++;
            if(s[i] != '1') sum2++;
        }else{
            if(s[i] != '1') sum1++;
            if(s[i] != '0') sum2++;
        }
    } 
    cout << min(sum1, sum2) << endl;

    return 0;
}