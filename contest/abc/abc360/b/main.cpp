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
    string S, T;
    cin >> S >> T;

    int N = S.size();
    int ok = 0;

    for(int i=1; i<N; i++){
        vector<string> vec;
        string tmp;
        int cnt = 0;
        for(int j=0; j<N; j++){
            tmp += S[j];
            cnt++;
            if(cnt>=i){
                vec.push_back(tmp);
                tmp = "";
                cnt = 0;
            }
        }
        if(tmp.size() > 0) vec.push_back(tmp);
    
        for(int j=0; j<i; j++){
            tmp = "";
            for(int k=0; k<vec.size(); k++){
                if(j < vec[k].size()){
                    tmp += vec[k][j];
                }          
            }
            if(tmp == T) ok = 1;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 