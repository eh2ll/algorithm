#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i = 1; i <= N; i += 2) cout << i << ' ';
    if(N & 1) N -= 1;
    for(int i = N; i > 0; i -= 2) cout << i << ' ';
    cout << '\n';

    return 0;
}