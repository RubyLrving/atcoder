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

int N, M;
string s, t;
int ans=0;
set<string> st;

void dfs(string t){

    int cnt = 0;

    rep(i, M) if(t[i] == '#') cnt++;

    if(cnt==M){
        int cnt=0;
        rep(i, N) if(s[i] == '#') cnt++; 
        if(cnt == N) ans=1;
        return;
    }

    if(st.count(t)>0){
        return;
    }

    st.insert(t);

    while(s.find(t) != string::npos){

        int p = s.find(t);

        rep(i, M) s[p+i] = '#';
    }

    int i;
    string temp = t;
    for(i=0; i<M; i++){
        if(t[i] != '#'){
            temp[i] = '#';
            break;
        }
    }
    dfs(temp);
    temp = t;
    for(i=M-1; i>=0; i--){
        if(t[i] != '#'){
            temp[i] = '#';
            break;
        }
    }
    dfs(temp);
}

int main() {

    cin >> N >> M;
    cin >> s >> t;

    dfs(t);

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 