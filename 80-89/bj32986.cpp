#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c; cin >> a >> b >> c;
    if(min({a, b, c}) <= 2) cout << 0 << '\n';
    else if(a == 3 && b == 3 && c == 3) cout << 0 << '\n';
    else{
        cout << (min({a, b, c}) - 1) / 2 << '\n';
    }

    return 0;
}