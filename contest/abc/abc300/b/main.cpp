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

vector<vector<char>> copy(vector<vector<char>> B, int H, int W, int y, int x){
    vector<vector<char>> C(H, vector<char>(W));
    rep(i, H){
        int ii = i+y;
        if(ii>=H) ii -= H;
        rep(j, W){
            int jj = j+y;
            if(jj>=W) jj -= W;
            C[i][j] = B[ii][jj];
        }
    }
    return C;
}

int check(vector<vector<char>> A, vector<vector<char>> B, int H, int W){
    int cnt=0;
    rep(i, H){
        rep(j, W){
            if(A[i][j] == B[i][j]){
                cnt++;
            }
        }
    }
    if(cnt==H*W) return 1;
    return 0;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W)), B(H, vector<char>(W));

    rep(i, H){
        string s;
        cin >> s;
        rep(j, W){
            A[i][j] = s[j];
        }
    }
    rep(i, H){
        string s;
        cin >> s;
        rep(j, W){
            B[i][j] = s[j];
        }
    }

    rep(i, H){
        rep(j, W){
            int ok = 1;
            rep(y, H){
                rep(x, W){
                    if (A[(y - i + H) % H][(x - j + W) % W] != B[y][x]) ok = 0;
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
} 