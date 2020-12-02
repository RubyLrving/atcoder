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

    int n, k;
    cin >> n >> k;

    int filed[8][8]={0};
    vector<int> vec(n);
    rep(i, n){
        vec[i] = i;
        rep(j, n){
            cin >> filed[i][j];
        }
    }

    int ans=0;
    do{
        if(vec[0]>0) continue;
        int sum=0;
        for(int i=1; i<n; i++){
            int y = vec[i];
            int x = vec[i-1];
            sum += filed[x][y];
            if(i==n-1) sum += filed[y][0];
        }
        if(sum==k) ans++;
    }while(next_permutation(vec.begin(), vec.end()));

    cout << ans << endl;
    return 0;
}