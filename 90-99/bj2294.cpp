#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int A[102], D[10004];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
    }
    sort(A, A + N, greater<int>());
    fill(D, D + 10004, INF);
    D[0] = 0;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j <= K; j += 1){
            if(D[j] != INF && j + A[i] <= K){
                D[j + A[i]] = min(D[j + A[i]], D[j] + 1);
            }
        }
    }

    cout << (D[K] == INF ? -1 : D[K]) << '\n';

    return 0;
}