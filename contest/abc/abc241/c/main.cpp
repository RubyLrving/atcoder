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
    rep(i, N) cin >> S[i];

    int ok=0;
    rep(i, N){
        rep(j, N){
            int cnt_x=0;
            int cnt_y=0;
            int cnt_r=0;
            int cnt_l=0;
            for(int p=0; p<6; p++){
                if(j+5<N && S[i][j+p]=='#') cnt_x++;
                if(i+5<N && S[i+p][j]=='#') cnt_y++;
                if(i+5<N && j+5<N && S[i+p][j+p]=='#') cnt_r++;
                if(i+5<N && j-5>=0 && S[i+p][j-p]=='#') cnt_l++;
            }

            if(cnt_x>=4 || cnt_y>=4 || cnt_r>=4 || cnt_l>=4){
                ok=1;
                break;
            }
        }
        if(ok) break;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 