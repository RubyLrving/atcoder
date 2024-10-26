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
   
    int n = s.size();
    int l=0, r=0, a_add=0;

    rep(i, n/2){
        if(s[i] == 'a') l++;
        else break;
    }
    for(int j = n-1; j>=0; j--){
        if(s[j] == 'a') r++;
        else break;
    }
    if(r-l>0){
        a_add = r-l;
    }

    string temp;
    rep(i, a_add){
        temp += 'a';
        n++;
    }
    s = temp + s;

    int low = 0;
    int high = n-1;
    int ok = 1;
    while (high > low){
        if(s[high] != s[low]){
            ok = 0;
            break;
        }
        low++;
        high--;
    }
    if(ok) cout << "Yes" <<endl;
    else cout << "No" <<endl;

    return 0;
} 