#include <bits/stdc++.h>

using namespace std;

int N;
int bor[202][202], vis[202][202];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            cin >> bor[i][j];
        }
    }

    vis[1][1] = 1;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            if(!vis[i][j] || (i == N && j == N)) continue;

            int cost = bor[i][j];
            vis[i][j + cost] = 1;
            vis[i + cost][j] = 1;
        }
    }

    if(vis[N][N]) cout << "HaruHaru" << '\n';
    else cout << "Hing" << '\n';

    return 0;
}