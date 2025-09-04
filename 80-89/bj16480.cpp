#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll R, r; cin >> R >> r;
    cout << R * (R - 2 * r) << '\n';

    return 0;
}