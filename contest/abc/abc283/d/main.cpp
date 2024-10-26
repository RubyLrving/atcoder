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
    stack<char> sk;
    set<char> st;
    for(int i=0; i<N; i++){
        if(S[i] == ')'){
            while(sk.size() > 0 && sk.top() != '('){
                st.erase(sk.top());
                sk.pop();
            }
            if(sk.size() == 0){
                 cout << "No" << endl;
                return 0;               
            }
            sk.pop();
        }else{
            if(S[i] != '(' && S[i] != ')'){
                if(st.find(S[i]) != st.end()){
                    cout << "No" << endl;
                    return 0;
                }
                st.insert(S[i]);
            }
            sk.push(S[i]);
        }
    }

    cout << "Yes" << endl;

    return 0;
} 