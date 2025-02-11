#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    map<int, int> mp;
    for(int i = 0; i < N + M; i += 1){
        int x; cin >> x;
        mp[x] += 1;
    }

    int cnt = 0;
    for(auto [k, v] : mp){
        if(v == 1) cnt += 1;
    }
    cout << cnt << '\n';

    return 0;
}