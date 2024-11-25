#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i += 1) arr.push_back(i);

    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        reverse(arr.begin() + a - 1, arr.begin() + b);
    }

    for(auto c : arr) cout << c << ' ';
    cout << '\n';

    return 0;
}