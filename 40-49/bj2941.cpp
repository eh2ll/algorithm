#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S; cin >> S;
    int ans = 0;
    map<string, int> mp;
    mp["c="] = 1;
    mp["c-"] = 1;
    mp["dz="] = 1;
    mp["d-"] = 1;
    mp["lj"] = 1;
    mp["nj"] = 1;
    mp["s="] = 1;
    mp["z="] = 1;

    for(int i = 0; i < S.size(); i += 1){
        string tmp = "";
        if(i + 1 < S.size()) tmp += S[i], tmp += S[i + 1];
        if(mp.count(tmp)){
            ans += mp[tmp];
            i += tmp.size() - 1;
            continue;
        }
        tmp = "";
        if(i + 2 < S.size()) tmp += S[i], tmp += S[i + 1], tmp += S[i + 2];
        if(mp.count(tmp)){
            ans += mp[tmp];
            i += tmp.size() - 1;
            continue;
        }
        ans += 1;
    }

    cout << ans << "\n";

    return 0;
}