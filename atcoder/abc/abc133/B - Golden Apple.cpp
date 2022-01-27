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
    int n;
    cin >> n;
    int A[50]={0};
    int res=0;
    rep(i, n){
        cin >> A[i];
        if(A[i]!=i+1) res++;
    }
    
    if(res>2) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
