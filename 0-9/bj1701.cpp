#include <bits/stdc++.h>

using namespace std;

string s;

vector<int> fail(string s){
    vector<int> f(s.size());
    int j = 0;
    for(int i = 1; i < s.size(); i += 1){
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int res = 0;
    for(int i = 0; i < s.size(); i += 1){
        string tmp = s.substr(i, s.size());
        vector<int> f = fail(tmp);

        res = max(res, *max_element(f.begin(), f.end()));
    }
    
    cout << res << '\n';

    return 0;
}