#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<list>
#include<set>
#include<bitset>
 
#define rep(i,n) for(int i=0; i<(n); i++)
#define fixed_setprecision(n) fixed << setprecision((n))
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9
 
using namespace std;
using ll =long long;
using P = pair<int,int>;
 
 
int main() {
    ll S, P;
    cin >> S >> P;
    
    bool res=false;
    for(ll i=1; i*i<=P; i++){
        ll M = P/i;
        if(S == M+i) res=true;
    }
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
 
    return 0;
}