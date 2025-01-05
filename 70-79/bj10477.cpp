#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int TC;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        int a, b; cin >> a >> b;
        ll tot = 0;
        for(int i = 0; (1 << i) - 1 <= a + b; i += 1){
            int tmp = (1 << i) - 1;
            if(tmp <= a && tmp <= b) tot += (1 << i);
            else{
                tot += min(tmp, b) - max(0, (tmp - a)) + 1;
            }
            // cout << tot << ' ';
        }
        // cout << '\n';

        cout << tot << '\n';
    }

    return 0;
}