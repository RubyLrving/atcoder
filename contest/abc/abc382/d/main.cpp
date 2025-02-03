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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> ans;
    auto f = [&](auto f, vector<int> a){
        if(a.size() == N){
            ans.push_back(a);
            return;
        }

        int b = 1;
        if(a.size() > 0) b = a.back() + 10;
        a.push_back(b);
        while(a.back() + 10*(N-a.size())<=M){
            f(f, a);
            a.back()++;
        }
    };

    f(f, vector<int>());

    cout << ans.size() << endl;
    rep(i, ans.size()){
        for(auto a:ans[i]){
            cout << a << ' ';
        }
        cout << endl;
    }

    return 0;
} 
