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
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    for(auto &s:S) cin >> s; 

    int ans=0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        map<char, int> mp;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) {
                for(auto c:S[i]){
                    mp[c]++;
                }
            }
        }

        int cnt=0;
        for(auto m:mp){
            if(m.second == K) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
} 