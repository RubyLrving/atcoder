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
    vector<int> A(N+1), B(N+1);
    repx(i, 1, N+1){
        int no;
        cin >> no;
        A[i] = no;
        B[no] = i;
    }

    vector<P> v;
    repx(i, 1, N+1){
        if(B[i] == i) continue;

        int no1 = B[i];
        int no2 = B[A[i]];
        int no3 = A[i];
        v.push_back(P(no2, no1));
        swap(A[no1], A[no2]);
        swap(B[i], B[no3]);
    }

    cout << v.size() << endl;
    rep(i, v.size()){
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
} 