#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int N;
int arr[50004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fill(arr, arr + 50001, inf);
    arr[N] = 0;

    for(int k = N; k >= 0; k -= 1){
        if(arr[k] == inf) continue;

        for(int i = sqrt(k); i > 0; i -= 1){
            arr[k - i * i] = min(arr[k - i * i], arr[k] + 1);
        }
    }

    cout << arr[0] << '\n';

    return 0;
}