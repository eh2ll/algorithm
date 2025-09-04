#include <bits/stdc++.h>

using namespace std;

string A[502];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C; cin >> R >> C;
    for(int i = 0; i < R; i += 1){
        cin >> A[i];
    }

    bool flag = 1;
    for(int i = 0; i < R; i += 1){
        for(int j = 0; j < C; j += 1){
            if(A[i][j] == 'S'){
                if(i - 1 >= 0){
                    if(A[i - 1][j] == 'W') flag = 0;
                }
                if(i + 1 < R){
                    if(A[i + 1][j] == 'W') flag = 0;
                }
                if(j - 1 >= 0){
                    if(A[i][j - 1] == 'W') flag = 0;
                }
                if(j + 1 < C){
                    if(A[i][j + 1] == 'W') flag = 0;
                }
            }
        }
    }

    if(flag){
        cout << "1\n";
        for(int i = 0; i < R; i += 1){
            for(int j = 0; j < C; j += 1){
                if(A[i][j] == '.') cout << 'D';
                else cout << A[i][j];
            }
            cout << '\n';
        }
    } else {
        cout << "0\n";
    }

    return 0;
}