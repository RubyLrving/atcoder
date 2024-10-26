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

char ch1[4] = {'H' , 'D' , 'C' , 'S'};
char ch2[13] = {'A' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};

int main() {
    int N;
    cin >> N;
    map<char, int> mp1, mp2;
    rep(i, 4) mp1[ch1[i]] = 1;
    rep(i, 13) mp2[ch2[i]] = 1;

    set<string> st;
    rep(i, N){
        string s;
        cin >> s;
        if(st.find(s) == st.end()){
            st.insert(s);
        }else{
            cout << "No" << endl;
            return 0;           
        }
    }

    for(auto s:st){
        if(mp1.find(s[0]) == mp1.end() || mp2.find(s[1]) == mp2.end()){
            cout << "No" << endl;
            return 0;
        }  
    }
    cout << "Yes" << endl;

    return 0;
} 