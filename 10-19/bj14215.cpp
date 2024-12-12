#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    int mn = min({a, b, c});
    int mx = max({a, b, c});
    int mi = a + b + c - mn - mx;

    cout << (mn + mi) + min(mx, (mn + mi - 1)) << '\n';

    return 0;
}