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
    int N, Q;
    cin >> N >> Q;

    vector<P> v;
    v.push_back(P(1, 0));

    for(int i=0; i<Q; i++){
        int q;
        cin >> q;

        if(q == 1){
            char c;
            cin >> c;
            P p = v.back();
            if(c == 'R') p.first++;
            if(c == 'L') p.first--;
            if(c == 'U') p.second++;
            if(c == 'D') p.second--;
            v.push_back(p);
        }

        if(q == 2){
            int p;
            cin >> p;

            if(v.size() <= p){
                int n = p - v.size();
                cout << v[0].first + n << ' ' << 0 << endl;
            }else{
                int n = v.size() - p - 1;
                cout << v[n+1].first << ' ' << v[n+1].second << endl;
            }
        }
    }


    return 0;
} 