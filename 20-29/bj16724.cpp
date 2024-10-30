#include <bits/stdc++.h>

using namespace std;

int N, M;
string arr[1003];
int vis[1003][1003];

map<char, pair<int, int>> mp;

void dfs(int x, int y, int col){
    vis[x][y] = col;

    auto [dx, dy] = mp[arr[x][y]];
    if(!vis[x + dx][y + dy]){
        dfs(x + dx, y + dy, col);
    }
    
    vis[x][y] = vis[x + dx][y + dy];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    int col = 0;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < M; j += 1){
            if(vis[i][j]) continue;
            col += 1;
            dfs(i, j, col);
            if(col != vis[i][j]) col -= 1;
        }
    }
    
    cout << col << '\n';
    // for(int i = 0; i < N; i += 1){
    //     for(int j = 0; j < M; j += 1){
    //         cout << vis[i][j];
    //     }
    //     cout << '\n';
    // }

    return 0;
}