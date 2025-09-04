#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<int> A(N + 1);
    for(int i = 0; i < M; i += 1){
        int a, b, c; cin >> a >> b >> c;
        for(int j = a; j <= b; j += 1){
            A[j] = c;
        }
    }

    for(int i = 1; i <= N; i += 1){
        cout << A[i] << ' ';
    }
    cout << '\n';

    return 0;
}