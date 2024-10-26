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
    int N, Q;
    cin >> N >> Q;
    vector<int> ball_to_pos(N), pos_to_ball(N);

    for(int i=0; i<N; i++){
        ball_to_pos[i] = i;
        pos_to_ball[i] = i;
    }

    for(int i=0; i<Q; i++){
        int q;
        cin >> q;
        int p0 = ball_to_pos[q-1];
        int p1 = p0 + 1;
        if(p1 == N) p1 -= 2;
        int q2 = pos_to_ball[p1];

        swap(ball_to_pos[q-1], ball_to_pos[q2]);
        swap(pos_to_ball[p0], pos_to_ball[p1]);
    }

    for(int i=0; i<N; i++){
        if(i != N-1) cout << pos_to_ball[i] + 1 << ' ';
        else cout << pos_to_ball[i] + 1 << endl;
    }

    return 0;
} 