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
#include<cctype>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    
    vector<ll> A(n+1);
    for(int i=1; i<n+1; i++){
        cin >> A[i];
        if(i>0) A[i] += A[i-1];
    }
    
    rep(i, n+1){
        ll max_a=0;
        rep(j, n+1){
            if(j-i<0) continue;
            if(max_a<A[j]-A[j-i]) max_a = A[j]-A[j-i];
        }
        if(i>0) cout << max_a << endl;
    }
    
    return 0;
}
