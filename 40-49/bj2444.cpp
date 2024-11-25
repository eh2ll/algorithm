#include <bits/stdc++.h>

using namespace std;

int N;
char bor[202][202];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        for(int j = 0; j < 2 * N - 1; j += 1){
            if(N - i - 1 <= j && j < N + i) bor[i][j] = '*';
            else bor[i][j] = ' ';
        }
    }
    for(int i = N; i < 2 * N - 1; i += 1){
        for(int j = 0; j < 2 * N - 1; j += 1){
            if(N - (2 * N - i - 2) - 1 <= j && j < N + (2 * N - i - 2)) bor[i][j] = '*';
            else bor[i][j] = ' ';
        }
    }

    for(int i = 0; i < 2 * N - 1; i += 1){
        for(int j = 0; j < 2 * N - 1; j += 1){
            if(j < N || bor[i][j] == '*') cout << bor[i][j];
        }
        cout << '\n';
    }

    return 0;
}