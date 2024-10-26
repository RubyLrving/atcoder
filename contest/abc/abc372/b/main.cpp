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

int sum(vector<int> A){
    int n = A.size();
    int ans = 0;
    rep(i, n) ans += A[i];
    return ans;
}

int main() {
    int M;
    cin >> M;

    vector<int> A;
    while(0<M){
        int a = 0;
        while(pow(3, a + 1) <= M) a++;
        A.push_back(a);
        M -= pow(3, a);   
    }

    cout << A.size() << endl;
    for(int i=0; i<A.size(); i++){
        cout << A[i];
        if(i+1<A.size()) cout << ' ';
        else cout << endl;
    }

    return 0;
} 