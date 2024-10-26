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

int main() {
    int N;
    cin >> N;

    vector<double> l(N);
    vector<double> r(N);

    rep(i, N){
        int t;
        cin >> t >> l[i] >> r[i];

        if(t==2) r[i] = r[i] - 0.1;
        if(t==3) l[i] = l[i] + 0.1;
        if(t==4){
            l[i] = l[i] + 0.1;
            r[i] = r[i] - 0.1;
        }
    }


    int res=0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){

            //res += (max(l[i],l[j]) <= min(r[i],r[j]));
            int ok=0;
            if(l[i] <= l[j] && l[j] <= r[i]) ok++;
            if(l[i] <= r[j] && r[j] <= r[i]) ok++;
            if(l[j] <= l[i] && l[i] <= r[j]) ok++;
            if(l[j] <= r[i] && r[i] <= r[j]) ok++;
            if(ok) res++;
            // cout << l[i] << ' ' << r[i] << ' ' << l[j] << ' ' << r[j] << endl;
        }
    }
    cout << res <<  endl;

    return 0;
}