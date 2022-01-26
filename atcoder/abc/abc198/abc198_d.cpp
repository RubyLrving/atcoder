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

#define DISPLAY_CNT 10
ll h[DISPLAY_CNT] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
map<char, ll> m;

ll SendMoreMoney(string S){
    ll n=0;
    ll l=S.length()-1;
    for(auto s:S){
        n += m[s] * pow(10, l);
        l--;
    }
    return n;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    for(auto s:s1) m[s]=0;
    for(auto s:s2) m[s]=0;
    for(auto s:s3) m[s]=0;

    if(m.size()>DISPLAY_CNT){
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    do{
        ll cnt=0;
        for(auto &itr:m){
            itr.second = h[cnt];
            cnt++;
        }
        if(m[s1[0]] == 0 || m[s2[0]] == 0 || m[s3[0]] == 0) continue;

        ll n1=SendMoreMoney(s1);
        ll n2=SendMoreMoney(s2);
        ll n3=SendMoreMoney(s3);

        if(n1 + n2 == n3){
            cout << n1 << endl << n2 << endl << n3 << endl;
            return 0;
        }

    }while(next_permutation(h, h+DISPLAY_CNT));

    cout << "UNSOLVABLE" << endl;
    
    return 0;
}