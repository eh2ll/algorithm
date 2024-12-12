#include <bits/stdc++.h>

using namespace std;

int N, K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    if(N > K){
        if(K & 1){
            if(N & 1) cout << N - 1 << '\n';
            else cout << N << '\n';
        }
        else{
            cout << N << '\n';
        }
    }
    else cout << 0 << '\n';

    return 0;
}