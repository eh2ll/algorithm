#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    int minA = 10001, minB = 10001, maxA = -10001, maxB = -10001;
    for(int i = 0; i < N; i += 1){
        int x, y; cin >> x >> y;
        minA = min(minA, x);
        maxA = max(maxA, x);
        minB = min(minB, y);
        maxB = max(maxB, y);
    }

    int res = (maxB - minB) * (maxA - minA);

    cout << res << '\n';

    return 0;
}