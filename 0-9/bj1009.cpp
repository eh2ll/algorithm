#include <bits/stdc++.h>

using namespace std;

int sol(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res *= (a % 10);
            res %= 10;
        }
        b >>= 1;
        a = ((a % 10) * (a % 10)) % 10;
    }
    if(res == 0) res += 10;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int a, b; cin >> a >> b;
        cout << sol(a, b) << '\n';
    }

    return 0;
}