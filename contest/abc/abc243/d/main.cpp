#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
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

int main() {
    ll N;
    ll X;
    cin >> N >> X;

    string s;
    cin >> s;
    deque<char> deq;
    rep(i, N){
        if(s[i] == 'U' && deq.size()>0 && deq.back() != 'U'){
            deq.pop_back();
        }else{
            deq.push_back(s[i]);
        }
    }

    while(deq.size()>0){
        char s = deq.front();
        deq.pop_front();
        if(s == 'U') X = X/2;
        else if(s == 'L') X = X*2;
        else if(s == 'R') X = X*2+1;
    }
    cout << X << endl;

    return 0;
} 