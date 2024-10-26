#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9

using namespace std;
using ll =long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

int L;
ll res=0;

void dfs(vector<int> &A, int L){
    if(A.size()==12 && L==0){
        int cnt=0;
        rep(i, 12){
            if(A[1]!=1) cnt++;
        }
        int sum=1;
        rep(i, cnt) sum *= 12 - i;
        res += sum;
        return;
    }else if(L==0 || A.size()==12){
        return;
    }

    int prev_last = (A.empty()? 1:A.back());
    for(int add=prev_last; add<=L; add++){
        
        if(A.size()<12){
            A.push_back(add);
            dfs(A, L-add);
        }else{
            add = L;
            A.push_back(add);
            dfs(A, 0);
        }

        A.pop_back();
    }
}


int main(void) {
    cin >> L;
    vector<int> A;
    dfs(A, L-0);

    cout << res << endl;

    return 0;
}