#include <bits/stdc++.h>

using namespace std;

string bor[10], inp[10];

void press(int i, int j){
    bor[i][j] = (bor[i][j] == 'O' ? '#' : 'O');
    if(i > 0) bor[i - 1][j] = (bor[i - 1][j] == 'O' ? '#' : 'O');
    if(i < 9) bor[i + 1][j] = (bor[i + 1][j] == 'O' ? '#' : 'O');
    if(j > 0) bor[i][j - 1] = (bor[i][j - 1] == 'O' ? '#' : 'O');
    if(j < 9) bor[i][j + 1] = (bor[i][j + 1] == 'O' ? '#' : 'O');
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 10; i += 1){
        cin >> inp[i];
    }

    int ans = 101;
    for(int bit = 0; bit < (1 << 10); bit += 1){
        for(int i = 0; i < 10; i += 1) bor[i] = inp[i];
        int cnt = 0;
        for(int i = 0; i < 10; i += 1){
            if(bit & (1 << i)){
                cnt += 1;
                press(0, i);
            }
        }

        for(int i = 1; i < 10; i += 1){
            for(int j = 0; j < 10; j += 1){
                if(bor[i - 1][j] == '#') continue;
                cnt += 1;
                press(i, j);
            }
        }
        
        bool isValid = 1;
        for(int i = 0; i < 10; i += 1){
            if(bor[9][i] == 'O'){
                isValid = 0;
                break;
            }
        }
        if(isValid){
            ans = min(ans, cnt);
        }
    }

    if(ans == 101) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}