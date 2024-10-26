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
    vector<tuple<int, int, int>> query(Q);
    rep(i, Q){
        int q = 0, x = 0, y = 0;
        cin >> q;
        if(q == 1) cin >> x >> y;
        if(q == 2) cin >> x;
        if(q == 3) cin >> x;       
        query[i] = {q, x, y};
    }

    vector<map<int, int>> v(N);
    map<int, set<int>> mp;
    rep(i, Q){
        int q = get<0>(query[i]);
        if(q == 1){
            int x = get<1>(query[i]);
            int y = get<2>(query[i]);
            v[y-1][x]++;
            mp[x].insert(y-1);
        }
        if(q == 2){
            int x = get<1>(query[i]);
            map<int, int> mp = v[x-1];

            int cnt = 0;
            for(auto m:mp){
                for(int j=0; j<m.second; j++){
                    cout << m.first;
                    if(j<m.second-1) cout << ' ';
                }
                (cnt<mp.size()-1)? cout << ' ' :cout << endl;
                cnt++;
            }
        }
        if(q == 3){
            int x = get<1>(query[i]);
            set<int> st = mp[x];
            int cnt = 0;
            for(auto s:st){
                cout << s + 1;
                (cnt<st.size()-1)? cout << ' ' :cout << endl;
                cnt++;
            }
        }
    }

    return 0;
} 