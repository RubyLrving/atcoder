#include <bits/stdc++.h>
#include <atcoder/all>
 
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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<pair<char, int>> rle;
    for(auto c:S){
        if(rle.size() && rle.back().first == c){
            rle.back().second++;
        }else{
            rle.push_back({c, 1});
        }
    }

    int cnt = 0;
    for(int i=0; i<rle.size(); i++){
        if(rle[i].first == '1'){
            cnt++;
            if(cnt == K-1){
                swap(rle[i+2], rle[i+1]);
            }
        }
    }

    string ans;
    for(auto [c, cnt]:rle){
        for(int i=0; i<cnt; i++){
            ans += c;
        }
    }
    cout << ans << endl;

    return 0;
} 