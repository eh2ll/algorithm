#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    assert(N == 5);
    for(int i = N; i > 0; i -= 1){
        cout << i << '\n';
    }

    return 0;
}