#include <bits/stdc++.h>

using namespace std;
using ld = long double;

ld arr[1003];
ld mx;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    ld tot = 0;
    for(int i = 0; i < N; i += 1){
        tot += arr[i] * 100 / mx;
    }

    cout << tot / N << '\n';

    return 0;
}