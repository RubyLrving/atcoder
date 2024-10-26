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

std::string itoh(int x, int size = 0) {
    char hex_buf[16];
    sprintf(hex_buf, "%X", x);
    std::string hex_str = hex_buf;
    if (size == 0) {
        return hex_str;
    }
    std::string front;
    if (x >= 0) front = "0";
    else front = "F";
    // 指定のサイズになるまで文字を増やす
    int diff = size - hex_str.length();
    for (int i=0; i < diff; i++){
        hex_str = front + hex_str;
    }
    // 指定のサイズになるまで文字を減らす
    if (diff < 0) {
        hex_str.erase(0, -diff);
    }
    return hex_str;
}

int main() {
    int N;
    cin >> N;

    string res = itoh(N, 2);

    cout << res << endl;

    return 0;
} 