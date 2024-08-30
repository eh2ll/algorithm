#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int res = 0;
    for(int i = 0; i < N - 2; i += 1){
        for(int j = i + 1; j < N - 1; j += 1){
            int k = lower_bound(arr + j + 1, arr + N, M - (arr[i] + arr[j])) - arr;
            
            if(arr[i] + arr[j] + arr[k] == M) res = M;
            if(k - 1 > j) res = max(res, arr[i] + arr[j] + arr[k - 1]);
        }
    }

    cout << res << '\n';

    return 0;
}