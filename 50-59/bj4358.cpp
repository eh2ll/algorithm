#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int tot = 0;
    while(getline(cin, s)){
        mp[s] += 1;
        tot += 1;
    }

    cout.precision(4);
    cout << fixed;
    for(auto i : mp){
        cout << i.first << ' ' << 100.0 * i.second / tot << '\n';
    }

    return 0;
}