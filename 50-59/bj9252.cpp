#include <bits/stdc++.h>

using namespace std;

int arr[1003][1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a = "0", b = "0";
    string tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    a += tmp1;
    b += tmp2;

    for(int i = 1; i <= a.size() - 1; i += 1){
        for(int j = 1; j <= b.size() - 1; j += 1){
            if(a[i] == b[j]) arr[i][j] = arr[i - 1][j - 1] + 1;
            else arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }

    cout << arr[a.size() - 1][b.size() - 1] << '\n';

    string ret = "";
    int x = a.size() - 1, y = b.size() - 1;
    while(x >= 1 && y >= 1){
        if(arr[x][y] == arr[x - 1][y]){
            x -= 1;
        }
        else if(arr[x][y] == arr[x][y - 1]){
            y -= 1;
        }
        else{
            ret += a[x];
            x -= 1;
            y -= 1;
        }
    }

    reverse(ret.begin(), ret.end());

    if(ret.size() > 0) cout << ret << '\n';

    return 0;
}