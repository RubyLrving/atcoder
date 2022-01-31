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

string color[] = {"灰色", "茶色", "緑色", "水色", "青色", "黄色", "橙色", "赤色", "黒色"};

int main() {
    int N;
    cin >> N;

    map<string, int> mp;
    rep(i, N){
        int a;
        cin >> a;

        if(1<=a && a<=399){
            mp[color[0]]++;
        }else if(400<=a && a<=799){
            mp[color[1]]++;
        }else if(800<=a && a<=1199){
            mp[color[2]]++;
        }else if(1200<=a && a<=1599){
            mp[color[3]]++;
        }else if(1600<=a && a<=1999){
            mp[color[4]]++;
        }else if(2000<=a && a<=2399){
            mp[color[5]]++;
        }else if(2400<=a && a<=2799){
            mp[color[6]]++;
        }else if(2800<=a && a<=3199){
            mp[color[7]]++;
        }else{
            mp[color[8]]++;
        }
    }

    int p = mp[color[8]];
    int cnt_min = 0;
    int cnt_max = 0;

    for(auto m:mp){
        if(m.first != "黒色") cnt_max++;
        else cnt_max += m.second;
        if(m.second > 0) if(m.first != "黒色") cnt_min++;
    }
    if(cnt_min==0 && mp[color[8]] > 0) cnt_min++;
    cout << cnt_min << ' ' << cnt_max << endl;

    return 0;
} 