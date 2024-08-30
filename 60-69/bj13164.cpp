#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[300005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int pre = 0;
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        if(i > 0) arr[i - 1] = x - pre;
        pre = x;
    }

    sort(arr, arr + N - 1);

    int tot = 0;
    for(int i = 0; i < N - K; i += 1){
        tot += arr[i];
    }

    cout << tot << '\n';

    return 0;
}