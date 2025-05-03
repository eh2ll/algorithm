#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bor[1000006];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 1000000; i += 1){
        for(int j = i; j <= 1000000; j += i){
            bor[j] += i;
        }
        bor[i] += bor[i - 1];
    }

    int tc; cin >> tc;
    while(tc--){
        int x; cin >> x;
        cout << bor[x] << '\n';
    }

    return 0;
}