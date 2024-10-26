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

int H = 9;
int W = 9;
vector<P> graph;

bool isSquare(vector<int>& x, vector<int>& y){
	vector<int> v;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++) {
			int dx = x[i] - x[j], dy = y[i] - y[j];
			v.push_back(dx * dx + dy * dy);
		}
	sort(v.begin(), v.end());
	int l = v[0];
	if (l == 0) return false; 
	return v[0]==l && v[1]==l && v[2]==l && v[3]==l && v[4]==l*2 && v[5]==l*2;
}

void solve(vector<string> S){
    rep(i, H){
        rep(j, W){
            if(S[i][j] == '#') graph.push_back(P(i+1, j+1));
        }
    }

    int n = graph.size();
    int res = 0;
    repx(i, 0, n){
        repx(j, i, n){
            repx(k, j, n){
                repx(l, k, n){
                    vector<int> x({graph[i].first, graph[j].first, graph[k].first, graph[l].first});
                    vector<int> y({graph[i].second, graph[j].second, graph[k].second, graph[l].second});
                    if(isSquare(x, y)){
                        res++;
                    }
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    solve(S);
    return 0;
} 