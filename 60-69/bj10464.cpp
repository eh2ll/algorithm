#include <bits/stdc++.h>

using namespace std;

int TC;

int sol(int x) {
    if(x % 4 == 0) return x;
    else if(x % 4 == 1) return 1;
    else if(x % 4 == 2) return x + 1;
    else return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        int S, F; cin >> S >> F;
        cout << (sol(F) ^ sol(S - 1)) << "\n";
    }

    return 0;
}