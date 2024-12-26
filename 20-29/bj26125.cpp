#include <bits/stdc++.h>

using namespace std;

const int inf = 300'000'001;
int N, M, S, T, Q;
int bor[302][302];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> S >> T;
    
    for(int i = 0; i < 302; i += 1) fill(bor[i], bor[i] + 302, inf);
    for(int i = 0; i < 302; i += 1) bor[i][i] = 0;
    
    for(int i = 0; i < M; i += 1){
        int a, b, c; cin >> a >> b >> c;
        bor[a][b] = min(bor[a][b], c);
    }

    for(int k = 1; k <= N; k += 1){
        for(int i = 1; i <= N; i += 1){
            for(int j = 1; j <= N; j += 1){
                if(bor[i][k] + bor[k][j] < bor[i][j]){
                    bor[i][j] = bor[i][k] + bor[k][j];
                }
            }
        }
    }

    cin >> Q;
    while(Q--){
        int a1, b1, c1; cin >> a1 >> b1 >> c1;
        int a2, b2, c2; cin >> a2 >> b2 >> c2;

        int mn = bor[S][T];
        mn = min(mn, bor[S][a1] + c1 + bor[b1][T]);
        mn = min(mn, bor[S][a2] + c2 + bor[b2][T]);
        mn = min(mn, bor[S][a1] + c1 + bor[b1][a2] + c2 + bor[b2][T]);
        mn = min(mn, bor[S][a2] + c2 + bor[b2][a1] + c1 + bor[b1][T]);
        
        if(mn == inf) cout << -1 << '\n';
        else cout << mn << '\n';
    }

    return 0;
}