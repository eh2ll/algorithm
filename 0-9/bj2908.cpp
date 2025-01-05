#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b; cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n1 = stoi(a);
    int n2 = stoi(b);
    int mx = max(n1, n2);

    cout << mx << '\n';

    return 0;
}