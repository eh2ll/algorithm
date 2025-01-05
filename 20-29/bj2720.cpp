#include <bits/stdc++.h>

using namespace std;

int T, N;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        cin >> N;
        int cnt = 0;
        if(N >= 25){
            cout << N / 25 << ' ';
            N %= 25;
        }
        else cout << 0 << ' ';

        if(N >= 10){
            cout << N / 10 << ' ';
            N %= 10;
        }
        else cout << 0 << ' ';

        if(N >= 5){
            cout << N / 5 << ' ';
            N %= 5;
        }
        else cout << 0 << ' ';

        cout << N << '\n';

    }
}