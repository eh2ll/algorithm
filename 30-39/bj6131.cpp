#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> sq;
    for(int i = 1; i <= 500; i += 1){
        sq.push_back(i * i);
    }

    int cnt = 0;
    for(auto c : sq){
        if(binary_search(sq.begin(), sq.end(), c + N)) cnt += 1;
    }

    cout << cnt << '\n';

    return 0;
}