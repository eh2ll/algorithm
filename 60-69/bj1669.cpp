#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y; cin >> x >> y;
    int diff = y - x;

    long long id = 0;
    while(id * id + id <= diff) id += 1;
    id -= 1;

    int left = diff - id * id - id;
    int ad = 1;
    if(left > id + 1) ad = 2;
    else if(left == 0) ad = 0;

    cout << 2 * id + ad << '\n';

    return 0;
}