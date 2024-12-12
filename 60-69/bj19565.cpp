#include <bits/stdc++.h>

using namespace std;

int N;
int arr[1000006];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cout << N * N + 1 << '\n';

    for(int i = 0; i < 2 * N; i += 1){
        arr[i] = (i / 2 + 1);
    }

    int idx = 2 * N;
    for(int i = N; i > 1; i -= 1){
        for(int j = 1; j < i; j += 1){
            if(j != 1) arr[idx++] = i;
            arr[idx++] = j;
        }
    }

    for(int i = 0; i <= N * N; i += 1){
        cout << arr[i] << ' ';
    }
    cout << '\n';

    return 0;
}

// 1 1 2 2 3 3 4 4 1 4 2 4 3 1 3 2 1
// 1 1 2 2 3 3 1 3 2 1