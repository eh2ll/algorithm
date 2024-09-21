#include <bits/stdc++.h>

using namespace std;

int N, M;
string s;
string pn = "I";

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
    // cin.tie(0);

    cin >> N >> M;
    cin >> s;

    for(int i = 0; i < N; i += 1) pn += "OI";
    vector<int> f = fail(pn);

    vector<int> kmp(s.size());
    int j = 0, cnt = 0;
    for(int i = 0; i < s.size(); i += 1){
        while(j > 0 && s[i] != pn[j]) j = f[j - 1];
        if(s[i] == pn[j]) kmp[i] = ++j;
        if(j == pn.size()){
            cnt += 1;
        } 
    }

    cout << cnt << '\n';

    return 0;
}