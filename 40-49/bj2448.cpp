#include <bits/stdc++.h>

using namespace std;

int N;
char bor[10004][10004];

void drawing(int x, int y){
    bor[x][y] = '*';

    bor[x + 1][y - 1] = '*';
    bor[x + 1][y + 1] = '*';

    bor[x + 2][y - 2] = '*';
    bor[x + 2][y - 1] = '*';
    bor[x + 2][y    ] = '*';
    bor[x + 2][y + 1] = '*';
    bor[x + 2][y + 2] = '*';
}

void sol(int row, int col, int lev){
    // cout << row << ' ' << col << ' ' << lev << '\n';

    if(lev == 3){
        drawing(row, col);
        return;
    }

    int new_lev = lev / 2;
    sol(row, col, new_lev);
    sol(row + new_lev, col - new_lev, new_lev);
    sol(row + new_lev, col + new_lev, new_lev);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    sol(1, N, N);

    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N * 2 - 1; j += 1){
            if(!bor[i][j]) cout << ' ';
            else cout << bor[i][j];
        }
        cout << '\n';
    }

    return 0;
}