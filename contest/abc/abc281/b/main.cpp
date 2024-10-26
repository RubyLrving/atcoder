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
    string s;
    cin >> s;

    int N = s.size();
    if(N != 8){
        cout << "No" << endl;
        return 0;        
    }
    rep(i, N){
        //cout << s[i] - '0' << endl;

        if((i == 0 || i == 7) && 'A' - '0' <= s[i] - '0' && s[i] - '0' <= 'Z' - '0'){

        }else if(i == 1 && 1 <= s[i] - '0' && s[i] - '0' <= 9){

        }else if(1<i && i<7 && 0 <= s[i] - '0' && s[i] - '0' <= 9){

        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
} 