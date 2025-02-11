#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    string res = "";
    for(int i = 0; i < s.size(); i += 1){
        if('A' <= s[i] && s[i] <= 'Z') res += s[i];
    }

    cout << res << '\n';

    return 0;
}