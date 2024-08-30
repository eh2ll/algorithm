#include <bits/stdc++.h>

using namespace std;

long double D, H, W;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> D >> H >> W;
    long double tmp = sqrt(pow(H, 2) + pow(W, 2));

    cout << int(D * H / tmp) << ' ' << int(D * W / tmp) << '\n';

    return 0;
}