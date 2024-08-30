#include <bits/stdc++.h>
// #include <thread>
using namespace std;

string board[10];
string answer[10];

int chk1[10][10];
int chk2[10][10];
int chk3[10][10];

void checkBlock(){
    for(int i = 0; i < 9; i += 1){
        for(int j = 0; j < 9; j += 1){
            int nx = i / 3;
            int ny = j / 3;
            chk1[nx * 3 + ny][board[i][j] - '0'] = 1;
        }
    }
    return;
}

void checkRow(){
    for(int i = 0; i < 9; i += 1){
        for(int j = 0; j < 9; j += 1){
            chk2[i][board[i][j] - '0'] = 1;
        }
    }
    return;
}

void checkCol(){
    for(int i = 0; i < 9; i += 1){
        for(int j = 0; j < 9; j += 1){
            chk3[j][board[i][j] - '0'] = 1;
        }
    }
    return;
}

void sol(){
    for(int i = 0; i < 9; i += 1){
        for(int j = 0; j < 9; j += 1){
            if(answer[8][8]) return;
            if(board[i][j] != 0 + '0') continue;
            for(int k = 1; k < 10; k += 1){
                if(chk1[(i/3)*3 + (j/3)][k] == 1 || chk2[i][k] == 1 || chk3[j][k] == 1) continue;
                chk1[(i/3)*3 + (j/3)][k] = 1;
                chk2[i][k] = 1;
                chk3[j][k] = 1;
                board[i][j] = k + '0';
                
                // cout << i << ' ' << j << '\n';
                // for(int w = 0; w < 9; w += 1) cout << board[w] << '\n';
                // std::this_thread::sleep_for(std::chrono::milliseconds(50));

                sol();
                board[i][j] = '0';
                chk1[(i/3)*3 + (j/3)][k] = 0;
                chk2[i][k] = 0;
                chk3[j][k] = 0;
            }
            return;
        }
    }

    for(int i = 0; i < 9; i += 1) answer[i] = board[i];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i += 1){
        cin >> board[i];
    }

    checkBlock();
    checkRow();
    checkCol();
    sol();

    for(int i = 0; i < 9; i += 1) cout << answer[i] << '\n';

    return 0;
}