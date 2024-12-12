#include <bits/stdc++.h>

using namespace std;

int N, A, B;
int arr1[2003], arr2[2003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> A >> B;

    for(int i = 0; i < A; i += 1){
        cin >> arr1[i];
    }
    sort(arr1, arr1 + A, greater<int>());
    for(int i = 0; i < B; i += 1){
        cin >> arr2[i];
    }
    sort(arr2, arr2 + B, greater<int>());

    int res = 0, idx = 0;
    for(int i = 0; i < min(N / 2, B); i += 1){
        res += arr2[i];
        idx += 2;
        // cout << "arr2: " << arr2[i] << ' ' << res << '\n';
    }
    int j = 0;
    for(int i = idx; i < N; i += 1){
        res += arr1[j++];
        // cout << "arr1: " << arr1[j - 1] << ' ' << res << '\n';
    }
    for(int i = min(N / 2, B) - 1; i >= 0; i -= 1){
        if(j + 1 < A && arr2[i] < arr1[j] + arr1[j + 1]){
            res -= arr2[i];
            res += arr1[j] + arr1[j + 1];
            j += 2;
            // cout << "+-: " << arr2[i] << ' ' << arr1[j - 2] << ' ' << arr1[j - 1] << '\n';
        }
        else break;
    }

    cout << res << '\n';

    return 0;
}