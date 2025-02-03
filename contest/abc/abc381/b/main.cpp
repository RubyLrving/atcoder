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
    string S;
    cin >> S;
    int N = S.size();
    if(N%2==1){
        cout << "No" << endl;
        return 0;
    }

    for(int i=1; i <= N / 2; i++){
        if(S[2 * i - 2] != S[2 * i - 1]){
            cout << "No" << endl;
            return 0;            
        }
    }

    set<char> st;
    for(int i=1; i <= N / 2; i++){
        if(st.find(S[2 * i - 1]) != st.end()){
            cout << "No" << endl;
            return 0;            
        }
        st.insert(S[2 * i - 1]);
    }
    cout << "Yes" << endl;

    return 0;
} 
