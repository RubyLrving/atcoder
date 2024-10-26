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
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    set<P> st;
    rep(i, M){
        int x, y;
        cin >> x >> y;
        st.insert(P(x,y));
    }

    P p = P(0, 0);
    int hp = H;
    int cnt = 0;
    while(hp >= 0 && cnt < N){
    
        if(S[cnt] == 'R'){
            p.first++;
        }
        if(S[cnt] == 'L'){
            p.first--;
        }
        if(S[cnt] == 'U'){
            p.second++;
        }
        if(S[cnt] == 'D'){
            p.second--;
        }

        hp--;
        if(hp < 0) break;

        if(st.find(p) != st.end()){
            if(hp<K){
                hp = K;
                st.erase(p);
            }
        }
        cnt++;
    }

    if(cnt == N) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 