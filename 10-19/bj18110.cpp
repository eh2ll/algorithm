#include <bits/stdc++.h>

using namespace std;
using ld = long double;

int N, arr[300005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    int diff = round(ld(N) * 15 / 100);
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int tot = 0;
    for(int i = diff; i < N - diff; i += 1){
        tot += arr[i];
    }

    if(N == 0) cout << 0 << '\n';
    else cout << round(ld(tot) / (N - 2 * diff)) << '\n';

    return 0;
}