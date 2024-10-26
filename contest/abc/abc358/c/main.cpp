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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    int ans = N;
    for(int tmp=0; tmp < (1 << N); tmp++){
        bitset<16> bit(tmp);
        int cnt = 0;
        string t;
        rep(i, M) t += 'x';
        rep(i, N){
            if(bit.test(i) == 0){
                continue;
            }
            rep(j, M){
                if(S[i][j] == 'o'){
                    t[j] = 'o';
                }
            }
            cnt++;
        }
        int ok = 1;
        rep(i, M){
            if(t[i] == 'x'){
                ok = 0;
                break;
            }
        }
        if(ok){
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
} 