#include <bits/stdc++.h>

using namespace std;

int N, M, D;
int arr[1003][1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;
    int flag = 1;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= M; j += 1){
            cin >> arr[i][j];
            arr[i][j] += D * i;
        }
        sort(arr[i] + 1, arr[i] + M + 1);
        for(int j = 1; j <= M; j += 1){
            if(arr[i][j] <= arr[i - 1][j]) flag = 0;
        }
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}