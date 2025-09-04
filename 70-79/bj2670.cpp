#include <bits/stdc++.h>

using namespace std;
using ld = long double;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    ld ans = -1, mul = 1;
    for(int i = 0; i < N; i += 1){
        ld x; cin >> x;
        mul *= x;
        ans = max(ans, mul);
        mul = max(mul, 1.0L);
    }

    cout << fixed;
    cout.precision(3);

    cout << ans << '\n';

    return 0;
}