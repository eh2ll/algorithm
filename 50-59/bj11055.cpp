#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1003], dp[1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
        dp[i] = arr[i];
        for(int j = 0; j < i; j += 1){
            if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + arr[i]);
        }
    }

    int mx = 0;
    for(int i = 0; i < N; i += 1) mx = max(mx, dp[i]);
    cout << mx << '\n';

    return 0;

}