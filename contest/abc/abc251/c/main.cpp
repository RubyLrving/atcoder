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
    int N;
    cin >> N;
    map<string, int> mp;
    vector<tuple<int, string, int, int>> vec;
    for(int i=0; i<N; i++){
        string s;
        int t;
        cin >> s >> t;
        mp[s]++;
        vec.push_back(make_tuple(i+1, s, t, mp[s]));
    }

    sort(vec.begin(), vec.end(), [](const auto&x, const auto& y){
        return get<2>(x) == get<2>(y)?   get<0>(x) < get<0>(y): get<2>(x) > get<2>(y);
    });

    for(auto &v:vec){
        if(get<3>(v)>1) continue;
        cout << get<0>(v) << endl;
        return 0;
    }
    cout << 0 << endl;

    return 0;
} 
