#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e, f, c; cin >> e >> f >> c;
    int sum = e + f;
    int cnt = 0;
    while(sum >= c){
        cnt += sum / c;
        sum = sum % c + sum / c;
    }
    cout << cnt << '\n';

    return 0;
}