#include <bits/stdc++.h>

using namespace std;

int N;
map<string, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int res = 0;
    for(int i = 0; i < N; i += 1){
        string s; cin >> s;
        if(s == "ENTER"){
            res += mp.size();
            mp.clear();
        }
        else{
            mp[s] += 1;
        }
    }
    res += mp.size();

    cout << res << '\n';

    return 0;
}