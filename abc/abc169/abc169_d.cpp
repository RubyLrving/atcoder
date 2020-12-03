#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main(int argc, const char * argv[]) {
    ll n;
    cin >> n;

    ll value = 2;
    map<int, int> m;
    while(value * value <= n){
        if(n % value == 0){
            n = n / value;
            if(m.find(value) == m.end()) m.insert(make_pair(value, 1));
            else m[value]++;
        }else{
            value++;
        }
    }
    if(n != 1){
        if(m.find(n) == m.end()) m.insert(make_pair(n, 1));
        else m[n]++;
    }

    int res=0;
    for(map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++){
        int cnt=0;
        while(cnt<=itr->second){
            itr->second = itr->second - cnt;
            cnt++;
        }
        res += cnt-1;
    }
    cout << res << endl;

    return 0;
}