#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int a_sum=0;
    int b_sum=0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == 'a' && a_sum+b_sum<(a+b)){
            a_sum++;
            cout << "Yes" << endl;
        }else if(s[i] == 'b' && a_sum+b_sum<(a+b) && b_sum<b){
            b_sum++;
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}