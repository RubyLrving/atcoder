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

bool is_prime_number[1000];

int main() {
    is_prime_number[1]=true;
    for(int i=2; i<1000; i++){
        if(!is_prime_number[i]){
            for(int j=i+i; j<1000; j+=i){
                is_prime_number[j] = true;
            }
        }
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans=1;
    for(int i=a; i<=b; i++){
        int ok=0;
        for(int j=c; j<=d; j++){
            if(!is_prime_number[i+j]) ok=1;
        }
        if(!ok){
            ans=0;
            break;
        }
    }
    if(ans) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;

    return 0;
} 