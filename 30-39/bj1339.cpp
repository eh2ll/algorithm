#include <bits/stdc++.h>

using namespace std;

int N, idx;
int mp[30], res;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        string s; cin >> s;
        for(int j = s.size() - 1, k = 1; j >= 0; j -= 1, k *= 10){
            if(mp[s[j] - 'A'] == 0) idx += 1;
            mp[s[j] - 'A'] += k;
        }
    }

    for(int i = 0; i < idx; i += 1){
        auto mxid = max_element(mp, mp + 30) - mp;
        res += mp[mxid] * (9 - i);
        // cout << mxid << ' ' << mp[mxid] << ' ' << 9 - i << '\n';
        mp[mxid] = 0;
    }

    cout << res << '\n';

    return 0;
}