#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    s = "-";
    for(int i = 1; i <= 12; i += 1){
        string tmp = " ";
        while(tmp.size() < s.size()) tmp += tmp + tmp;
        s += tmp + s;
    }

    int N;
    while(cin >> N){
        int cnt = pow(3, N);
        for(int i = 0; i < cnt; i += 1) cout << s[i];
        cout << '\n';
    }

    return 0;
}