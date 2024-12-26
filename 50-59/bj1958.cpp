#include <bits/stdc++.h>

using namespace std;

string a, b, c;
int bor[102][102][102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    a = " " + a;
    b = " " + b;
    c = " " + c;

    for(int i = 1; i < a.size(); i += 1){
        for(int j = 1; j < b.size(); j += 1){
            for(int k = 1; k < c.size(); k += 1){
                if(a[i] == b[j] && b[j] == c[k]){
                    bor[i][j][k] = bor[i - 1][j - 1][k - 1] + 1;
                }
                else{
                    bor[i][j][k] = max({bor[i - 1][j][k], bor[i][j - 1][k], bor[i][j][k - 1]});
                }
            }
        }
    }

    cout << bor[a.size() - 1][b.size() - 1][c.size() - 1] << '\n';

    return 0;
}