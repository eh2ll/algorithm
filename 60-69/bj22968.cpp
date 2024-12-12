#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int T;
ll arr[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= 50; i += 1){
        arr[i] = arr[i - 1] + arr[i - 2] + 1;
        // cout << i << ' ' << arr[i] << '\n';
    }

    while(T--){
        int N; cin >> N;
        cout << upper_bound(arr, arr + 51, N) - arr - 1 << '\n';
    }

    return 0;
}