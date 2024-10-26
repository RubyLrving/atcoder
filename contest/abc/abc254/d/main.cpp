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
    ll N;
    cin >> N;
    vector<int> A;
    //  N以下の平方数を全て計算する
    for(int i=1; i*i<=N; i++){
        A.push_back(i*i);
    }

    ll ans = 0;
    // iを固定した時、jがとる値を計算する
    for(int i=1; i<=N; i++){
        ll t = i;
        // N以下の平方数でiを割る。
        // 大きい平方数から割らないと余りが出る。
        for(auto itr = A.rbegin(); (*itr) != 1; itr++){
            while(t%(*itr)==0) t /= *itr;
        }
        // 残った約数と、N以下の平方数をかけて、
        // N以下なら組み合わせの一つであると判定できる。
        for(auto itr = A.begin(); t * (*itr)<=N && itr != A.end(); itr++){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
} 