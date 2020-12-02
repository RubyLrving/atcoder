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

    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    cout << fixed << setprecision(10) << (sy*gx+sx*gy)/(sy+gy) << endl;
    return 0;
}