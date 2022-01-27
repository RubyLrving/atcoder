
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<list>
#include<set>
#include<bitset>
using namespace std;

int main() {
    int x;
    cin >> x;

    int ans=x;
    while(true){
        bool is_prime_number=true;
        for(int j=2; j*j<x; j++){
            if(ans%j==0) is_prime_number=false;
        }
        if(is_prime_number) break;
        ans++;
    }

    cout << ans << endl;

    return 0;
}