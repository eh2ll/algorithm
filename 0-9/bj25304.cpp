#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int K; cin >> K;
    int sum = 0;
    for(int i = 0; i < K; i += 1){
        int a, b; cin >> a >> b;
        sum += a * b;
    }

    if(N == sum) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}