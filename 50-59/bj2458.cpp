#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;
int N, M;
int bor[502][502];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        bor[a][b] = 1;
    }

    for(int k = 1; k <= N; k += 1){
        for(int i = 1; i <= N; i += 1){
            for(int j = 1; j <= N; j += 1){
                if(bor[i][k] && bor[k][j]){
                    bor[i][j] = 1;
                }
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= N; i += 1){
        int tmp = 0;
        for(int j = 1; j <= N; j += 1){
            tmp += bor[i][j] + bor[j][i];
        }
        if(tmp == N - 1) cnt += 1;
    }

    cout << cnt << '\n';

    return 0;
}