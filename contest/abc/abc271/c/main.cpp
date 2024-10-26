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
    int N;
    cin >> N;
    deque<int> dque;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    unique(A.begin(), A.end());
    for(int i=0; i<N; i++) dque.push_back(A[i]);    

    int index=1;
    while(dque.size()){
        int p = dque.front();
        if(index == p){
            dque.pop_front();
            index++;
        }else{
            int cnt=2;
            while(cnt>0){
                if(dque.size()>0) dque.pop_back(), cnt--;
                else break;
            }
            if(cnt==0) dque.push_front(index);
            else break;
        }
    }
    cout << index-1 << endl;

    return 0;
} 