#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        string s; cin >> s;
        if(s == "0") return 0;

        int len = s.size();
        bool flag = 1;
        for(int i = 0; i <= (len - 1) / 2; i += 1){
            if(s[i] != s[len - 1 - i]) flag = 0;
        }

        if(flag) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}