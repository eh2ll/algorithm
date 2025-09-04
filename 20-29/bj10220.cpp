#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;

        if(N == 4) cout << 2 << '\n';
        else if(N == 5) cout << 1 << '\n';
        else if(N <= 6) cout << 0 << '\n';
        else cout << 1 << '\n';
    }

    return 0;
}