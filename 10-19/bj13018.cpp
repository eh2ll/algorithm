#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    if(N == K){
        cout << "Impossible" << '\n';
    }
    else if(N == K + 1){
        for(int i = 1; i <= N; i += 1){
            cout << i << " ";
        }
        cout << '\n';
    }
    else{
        cout << N - K << ' ';
        for(int i = 1; i < N - K; i += 1) cout << i << ' ';
        for(int i = N - K + 1; i <= N; i += 1) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}