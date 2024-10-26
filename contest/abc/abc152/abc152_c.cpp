#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> P(n);
    for(int i=0; i<n; i++){
        cin >> P[i];
    }
    int ans=0;
    int cur_min=1e9;
    for(int i=0; i<n; i++){
        if(cur_min>=P[i]){
            cur_min=P[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}