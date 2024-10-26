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
    int n, q;
    string s,temp;
    cin >> n;
    cin >> s;
    cin >> q;

    string l[2] = {s.substr(0, n), s.substr(n, 2*n)};

    for(int i=0; i<q; i++){
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        if(t==1){
            swap(l[a/n][a%n], l[b/n][b%n]);
        }else if(t==2){
            swap(l[0], l[1]);
        }
    }

    cout << l[0] + l[1] << endl;
 
    return 0;
}