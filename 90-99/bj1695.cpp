#include <bits/stdc++.h>
using namespace std;

int N;
int arr[5050], dp[5050][5050];

int sol(int s, int e){
    if(s + 1 > e) return 0;
    if(dp[s][e] != -1) return dp[s][e];

    int cnt = 0;
    if(arr[s] == arr[e]) cnt = sol(s + 1, e - 1);
    else cnt = min(sol(s + 1, e), sol(s, e - 1)) + 1;

    return dp[s][e] = cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    int ret = sol(0, N - 1);
    cout << ret << '\n';

    return 0;
}