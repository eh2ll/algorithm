#include <bits/stdc++.h>

using namespace std;

int N, arr[1003];

tuple<int, int, int> xgcd(int a, int b){
    if(b == 0) return {a, 1, 0};

    auto [g, x, y] = xgcd(b, a % b);

    return {g, y, x - (a / b) * y};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    int mx = abs(arr[1] - arr[0]);
    for(int i = 1; i < N; i += 1){
        int diff = abs(arr[i] - arr[i - 1]);
        auto [g, x, y] = xgcd(mx, diff);
        mx = g;
    }

    cout << mx << '\n';

    return 0;
}