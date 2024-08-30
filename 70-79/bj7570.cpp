#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000006];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        arr[x] = arr[x - 1] + 1;
    }

    int mx = 0;
    for(int i = 1; i <= N; i += 1){
        mx = max(mx, arr[i]);
    }

    cout << N - mx << '\n';

    return 0;
}