#include <bits/stdc++.h>

using namespace std;

map<char, int, greater<char>> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    for(int i = 0; i < s.size(); i += 1){
        mp[s[i]] += 1;
    }

    for(auto [k, v] : mp){
        for(int i = 0; i < v; i += 1){
            cout << k;
        }
    }
    cout << '\n';

    return 0;
}