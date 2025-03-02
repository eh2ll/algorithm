#include <bits/stdc++.h>

using namespace std;

int N, M;
int bor[202][202], par[202][202];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < 202; i += 1) fill(bor[i], bor[i] + 202, 0x3f3f3f3f);
    for(int i = 0; i < 202; i += 1) bor[i][i] = 0;

    for(int i = 0; i < M; i += 1){
        int a, b, cost; cin >> a >> b >> cost;
        bor[a][b] = bor[b][a] = cost;
        par[a][b] = b;
        par[b][a] = a;
    }

    for(int k = 1; k <= N; k += 1){
        for(int i = 1; i <= N; i += 1){
            for(int j = 1; j <= N; j += 1){
                if(bor[i][j] > bor[i][k] + bor[k][j]){
                    bor[i][j] = bor[i][k] + bor[k][j];
                    if(par[i][k] == 0){
                        par[i][j] = k;
                    }
                    else{
                        par[i][j] = par[i][k];
                    }
                }
            }
        }
    }

    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            if(par[i][j] == 0) cout << '-' << ' ';
            else cout << par[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}