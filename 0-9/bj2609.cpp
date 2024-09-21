#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> solve(int a, int b){
    if(b == 0) return {a, 1, 0};

    auto [g, x, y] = solve(b, a % b);

    return {g, y, x - (a/b)*y};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    auto [g, x, y] = solve(a, b);

    cout << g << '\n' << a * b / g << '\n';

    return 0;
}