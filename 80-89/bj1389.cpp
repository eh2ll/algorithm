#include <bits/stdc++.h>

using namespace std;

const int inf = 101;
int N, M;
int arr[102][102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 102; i += 1) fill(arr[i], arr[i] + 102, inf);
    for(int i = 0; i < 102; i += 1) arr[i][i] = 0;

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int k = 1; k <= N; k += 1){
        for(int i = 1; i <= N; i += 1){
            for(int j = 1; j <= N; j += 1){
                if(arr[i][j] <= arr[i][k] + arr[k][j]) continue;
                arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    int mn = 10001, idx = 0;
    for(int i = 1; i <= N; i += 1){
        int tot = 0;
        for(int j = 1; j <= N; j += 1){
            tot += arr[i][j];
        }
        
        if(mn > tot){
            mn = tot;
            idx = i;
        }
    }

    cout << idx << '\n';

    return 0;
}