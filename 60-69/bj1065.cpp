#include <bits/stdc++.h>

using namespace std;

bool A[1'003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for(int i = 1; i <= 9; i += 1) A[i * 10 + (i - 1)] = 1, A[(i - 1) * 10 + i];
    for(int i = 1; i <= 9; i += 1) A[i] = A[i * 11] = A[i * 111] = 1;
    for(int k = 1; k <= 9; k += 1){
        for(int i = 1; i <= 9; i += 1){
            if(i - k >= 0) A[i * 10 + (i - k)] = A[(i - k) * 10 + i] = 1;
            if(i - 2 * k >= 0) A[i * 100 + (i - k) * 10 + (i - 2 * k)] = A[(i - 2 * k) * 100 + (i - k) * 10 + i] = 1;
        }
    }

    int cnt = 0;
    for(int i = 1; i <= N; i += 1) cnt += A[i];

    cout << cnt << '\n';

    return 0;
}