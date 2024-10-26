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
    
    ll color[1000007]={0};
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        color[a+1]++;
        color[b+2]--;
    }
    
    ll max_buyer=0;
    for(int i=1; i<1000003; i++){
        color[i] = color[i] + color[i-1];
        max_buyer = max(max_buyer, color[i]);
    }
    cout << max_buyer << endl;

    return 0;
}
