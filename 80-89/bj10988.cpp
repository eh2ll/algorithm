#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int sz = s.size();
    bool flag = 1;
    for(int i = 0; i < (sz + 1) / 2; i += 1){
        if(s[i] != s[sz - 1 - i]) flag = 0;
    }

    cout << flag << '\n';

    return 0;
}