#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d; cin >> a >> b >> c >> d;
    int ac = a * d + c * b, bd = b * d;
    for(int i = 2; i * i <= max(ac, bd); i += 1){
        while(ac % i == 0 && bd % i == 0) ac /= i, bd /= i;
    }

    cout << ac << ' ' << bd << '\n';

    return 0;
}