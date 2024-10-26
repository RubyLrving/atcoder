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

double dist(pair<double, double> a, pair<double, double> b){
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
    int N;
    double S, T;
    cin >> N >> S >> T;
    vector<pair<pair<double, double>, pair<double, double>>> abcd(N);
    rep(i, N){
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        abcd[i].first = {a, b};
        abcd[i].second = {c, d};
    }

    double ans = 1e9;
    for(int bit=0; bit<(1<<N); bit++){
        vector<pair<pair<double, double>, pair<double, double>>> temp(N);
        for(int i=0; i<N; i++){
            if((bit >> i)&1){
                temp[i].first = abcd[i].second;
                temp[i].second = abcd[i].first;
            }else{
                temp[i].first = abcd[i].first;
                temp[i].second = abcd[i].second;
            }
        }

        sort(temp.begin(), temp.end());

        do{
            double time = 0;
            pair<double, double> s = {0, 0};
            pair<double, double> t = temp[0].first;

            if(temp[0].first != s){
                time += dist(temp[0].first, {0, 0}) / S;
            }

            for(int i=0; i<N; i++){
                time += dist(temp[i].first, temp[i].second) / T;
                if(i<N-1 && temp[i].second != temp[i+1].first){
                    time += dist(temp[i].second, temp[i+1].first) / S;
                }
            }

            ans = min(time, ans);
        }while(next_permutation(temp.begin(), temp.end()));
    }
    cout << fixed_setprecision(6) << ans << endl;

    return 0;
} 