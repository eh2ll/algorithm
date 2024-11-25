#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int x; cin >> x;

    int sz = s.size(), op = 1, res = 0;
    for(int i = 0; i < sz; i += 1){
        if('0' <= s[sz - i - 1] && s[sz - i - 1] <= '9'){
            res += (s[sz - i - 1] - '0') * op;
        }
        else{
            res += (s[sz - i - 1] - 'A' + 10) * op;
        }

        op *= x;
    }

    cout << res << '\n';

    return 0;
}