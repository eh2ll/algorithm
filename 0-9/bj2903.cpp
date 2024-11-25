#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int tmp = 2;
    for(int i = 1; i <= N; i += 1) tmp = 2 * tmp - 1;

    cout << tmp * tmp << '\n';

    return 0;
}