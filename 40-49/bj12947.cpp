#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    stack<int> S;
    S.push(0);
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        if(x == 1) S.push(i);
    }

    int en = N + 1, mx = 0;
    while(!S.empty()){
        auto cur = S.top(); S.pop();
        mx = max(mx, (N - cur) + (en - cur - 1));
        en = cur;
    }

    cout << mx << '\n';

    return 0;
}