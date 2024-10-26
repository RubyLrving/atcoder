#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.141592653589793238;
 
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

void solve(ll a, ll b, ll c){

    if(!(a%2==0 && b%2==0 && c%2==0)){cout << 0 << endl; return;}

    ll ok=0;
    ll aa=0, bb=0, cc=0;
    while(1){
        aa= b / 2 + c / 2;
        bb= a / 2 + c / 2;
        cc= b / 2 + a / 2;
        
        if(a==aa && b==bb && c==cc){ok=-1; break;}
        else if(!(aa%2==0 && bb%2==0 && cc%2==0)){ok++; break;}
        a = aa; b = bb; c = cc; ok++;
    }
    cout << ok << endl;
}
 
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    solve(a, b, c);
 
    return 0;
}