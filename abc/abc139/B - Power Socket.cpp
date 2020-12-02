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
#define fix(n) fixed << setprecision((n))
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;
    
    int sum=1;
    int res=0;
    while(b>sum){
        sum += (a-1);
        res++;
    }
    cout << res << endl;

    return 0;
}
