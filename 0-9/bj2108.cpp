#include <bits/stdc++.h>

using namespace std;
using ld = long double;

int N;
map<int, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    ld tot = 0;
    for(int i = 0; i < N; i += 1){
        int x; cin >> x;
        tot += x;
        mp[x] += 1;
    }
    cout << int(round(tot / N)) << '\n';
    
    int idx = 0, res = 0;
    for(auto c : mp){
        idx += c.second;
        if(idx >= N / 2 + 1){
            res = c.first;
            break;
        }
    }
    cout << res << '\n';
    
    int seen = 0, mkey = 0, flag = 0;
    for(auto c : mp){
        if(c.second > seen){
            seen = c.second;
            mkey = c.first;
            flag = 1;
        }
        else if(c.second == seen){
            if(flag == 1) mkey = c.first;
            flag += 1;
        }
    }
    cout << mkey << '\n';

    auto mx = --mp.end(), mn = mp.begin();
    cout << mx->first - mn->first << '\n';

    // long double a = -9, b = 5;
    // cout << round(a / b) << ' ' << a / b << '\n';

    return 0;
}