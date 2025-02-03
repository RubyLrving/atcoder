#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

int main() {
    int N, W;
    cin >> N >> W;
    vector<P> A(N);
    rep(i, N){
        int x, y;
        cin >> x >> y;
        A[i] = {x, y};
    }

    sort(A.begin(), A.end(), [](const P& p1, const P& p2){
        return p1.second < p2.second;
    });

    map<int, vector<int>> mp;
    vector<int> idx(N);
    rep(i, N){
        mp[A[i].first].push_back(A[i].second);
        idx[i] = mp[A[i].first].size() - 1;
    }

    int cnt = 1e9+7;
    repx(j, 1, W+1){
        cnt = min(cnt, (int)mp[j].size());
    }
    
    int Q;
    cin >> Q;
    rep(i, Q){
        int t, a;
        cin >> t >> a;
        a--;
        if(idx[a] > cnt){
            cout << "Yes" << endl;
            continue;
        }

        int y = mp[A[a].first][idx[a]];
        if(y < t){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }

    return 0;
} 
