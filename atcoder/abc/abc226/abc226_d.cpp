#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
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

int gcd(int a, int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

int main() {
    int N;
    cin >> N;

    vector<int> x(N);
    vector<int> y(N);
    set<P> st;
    rep(i, N) cin >> x[i] >> y[i];

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            int xx = x[j] - x[i];
            int yy = y[j] - y[i];
            if(xx!=0 && yy!=0){
              int t = gcd(xx, yy);
              xx = xx/t;
              yy = yy/t;
            }else{
              if(xx != 0) xx = 1;
              if(yy != 0) yy = 1;
            }
            
            st.insert(P(xx, yy));
            st.insert(P(-xx, -yy));
        }
    }

    cout << st.size() << endl;

    return 0;
}