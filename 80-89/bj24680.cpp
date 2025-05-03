#include <bits/stdc++.h>

using namespace std;

int bor[20][20];
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 16; i += 1){
        for(int j = 1; j <= 16; j += 1){
            cin >> bor[i][j];
        }
    }

    // s += "D";
    // s += "R";
    // for(int i = 1; i <= 15; i += 1){
    //     for(int j = 1; j <= 14; j += 1){
    //         if(i % 2 == 1){
    //             s += "rrF";
    //         }
    //         else{
    //             s += "llF";
    //         }
    //     }
    //     if(i < 15) s += "D";
    // }
    // s += "R";
    // for(int i = 1; i <= 16; i += 1) s += "uuF";
    // for(int i = 1; i <= 16; i += 1) s += "llF";
    // for(int i = 1; i <= 15; i += 1) s += "ddF";
    // s += "D";

    // s += "D";
    // for(int i = 1; i <= 15; i += 1){
    //     if(i % 2 == 1){
    //         s += "R";
    //     }
    //     else{
    //         s += "L";
    //     }
    //     for(int j = 1; j <= 15; j += 1){
    //         if(i % 2 == 1){
    //             s += "rrF";
    //         }
    //         else{
    //             s += "llF";
    //         }
    //     }
    //     if(i < 16) s += "D";
    // }
    // for(int i = 1; i <= 15; i += 1) s += "uuF";
    // s += "U";
    // for(int i = 1; i <= 15; i += 1) s += "llF";
    // s += "L";
    // for(int i = 1; i <= 15; i += 1) s += "ddF";
    // s += "D";

    s += "D";
    s += "R";
    for(int i = 1; i <= 15; i += 1){
        for(int j = 1; j <= 14; j += 1){
            if(i % 2 == 1){
                s += "rFr";
            }
            else{
                s += "lFl";
            }
        }
        if(i < 15){
            if(i % 2 == 1) s += "DL";
            else s += "DR";
        }
    }
    s += "RR";
    for(int i = 1; i <= 15; i += 1) s += "uFu";
    s += "U";
    for(int i = 1; i <= 15; i += 1) s += "lFl";
    s += "L";
    for(int i = 1; i <= 15; i += 1) s += "dFd";
    s.pop_back();
    s += "D";

    cout << s.size() << '\n';

    int x = 1, y = 1;
    for(int i = 0; i < s.size(); i += 1){
        auto cur = s[i];
        if(cur == 'F') bor[x][y] ^= 1;
        else if(cur == 'U'){
            cout << "U " << x << ' ' << y << '\n';
            if(x - 1 < 1) continue;
            x -= 1;
        }
        else if(cur == 'D'){
            cout << "D " << x << ' ' << y << '\n';
            if(x + 1 > 16) continue;
            x += 1;
        }
        else if(cur == 'L'){
            // cout << "L " << x << ' ' << y << '\n';
            if(y - 1 < 1) continue;
            y -= 1;
        }
        else if(cur == 'R'){
            cout << "R " << x << ' ' << y << '\n';
            if(y + 1 > 16) continue;
            y += 1;
        }
        else if(cur == 'u'){
            if(x - 1 < 1) continue;
            if(bor[x][y]) continue;
            x -= 1;
        }
        else if(cur == 'd'){
            if(x + 1 > 16) continue;
            if(bor[x][y]) continue;
            x += 1;
        }
        else if(cur == 'l'){
            if(y - 1 < 1) continue;
            if(bor[x][y]) continue;
            y -= 1;
        }
        else if(cur == 'r'){
            if(y + 1 > 16) continue;
            if(bor[x][y]) continue;
            y += 1;
        }
    }

    int flag = 0;
    for(int i = 1; i <= 16; i += 1){
        for(int j = 1; j <= 16; j += 1){
            flag += bor[i][j];
            cout << bor[i][j];
        }
        cout << '\n';
    }
    cout << flag << '\n';
    cout << x << ' ' << y << '\n';
    cout << s << '\n';

    return 0;
}