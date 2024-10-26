#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
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
const long long INF = 1LL << 60;

int main() {
    int n;
    cin >> n;

    int max_n = pow(2, n);
    queue<P> que;
    rep(i, max_n){
        int a;
        cin >> a;

        que.push(make_pair(i+1, a));
    }

    P p1, p2;
    while(que.size()>1){
        p1 = que.front(); que.pop();
        p2 = que.front(); que.pop();

        if(p1.second < p2.second){
            que.push(p2);
        }else{
            que.push(p1);
        }
    }
    if(p1.second < p2.second){
        cout << p1.first << endl;
    }else{
        cout << p2.first << endl;
    }

    return 0;
}