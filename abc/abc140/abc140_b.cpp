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
    vector<int> A(n), B(n), C(n-1);
    
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];
    rep(i, n-1) cin >> C[i];
    
    int sum=0;
    rep(i, n){
        sum += B[A[i]-1];
        if(i-1>=0 && A[i-1]+1 == A[i]) sum += C[A[i-1]-1];
    }
    
    cout << sum << endl;

    return 0;
}
