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
    vector<string> S(N);
    for(auto &s:S) cin >> s;
    vector<vector<int>> num_cnt(10, vector<int>(10));

    vector<int> time(10);    
    for(int i=0; i<10; i++){
        for(int j=0; j<N; j++){
            int num = S[j][i] - '0';
            num_cnt[i][num]++;
        }
        for(int k=0; k<10; k++){
            if(num_cnt[i][k]>0) time[k] = max(time[k], (num_cnt[i][k] - 1) * 10 + i);           
        }
    }

    int ans = 1e9 + 7;
    for(int i=0; i<10; i++){
        ans = min(ans, time[i]);
    }
    cout << ans << endl;

    return 0;
} 