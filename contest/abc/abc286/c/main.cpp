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
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    ll ans = 1LL << 60;
    for(ll i=0; i<N; i++){
        ll money = A * i;
        string front;
        rep(j, i) front += S[j];

        string temp = S.substr(i, S.size() - i) + front;
        ll tn = temp.size();
        ll cnt = 0;
        for(ll j=0; j < temp.size() / 2; j++){
            if(temp[j] != temp[tn-1-j]){
                cnt++;
            }
        }
        money += cnt * B;
        ans = min(money, ans);
    } 
    cout << ans << endl;

    return 0;
} 