#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int fives[2'000'000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    fives[5] = 1;
    for(int i = 6; i < 2'000'000; i += 1){
        fives[i] = fives[i - 1];
        if(i % 1953125 == 0) fives[i] += 9;
        else if(i % 390625 == 0) fives[i] += 8;
        else if(i % 78125 == 0) fives[i] += 7;
        else if(i % 15625 == 0) fives[i] += 6;
        else if(i % 3125 == 0) fives[i] += 5;
        else if(i % 625 == 0) fives[i] += 4;
        else if(i % 125 == 0) fives[i] += 3;
        else if(i % 25 == 0) fives[i] += 2;
        else if(i % 5 == 0) fives[i] += 1;
    }

    string s; cin >> s;
    int cnt = 0, num1 = 0, idx = 0;
    string inp = "";
    for(int i = s.size() - 1; i >= 0; i -= 1){
        if(s[i] == '0') cnt += 1;
        else{
            idx = i;
            break;
        }
    }
    for(int i = idx; i >= 0; i -= 1){
        inp += s[i];
        num1 += 1;
        if(num1 == 10) break;
    }
    reverse(inp.begin(), inp.end());
    ll num = stoll(inp);

    ll res = 1;
    vector<ll> ans;
    ans.push_back(-1);
    for(ll i = 1; i <= 1'000'000; i += 1){
        res *= i;
        if(i % 1953125 == 0){
            res /= 1000000000;
        }
        else if(i % 390625 == 0){
            res /= 100000000;
        }
        else if(i % 78125 == 0){
            res /= 10000000;
        }
        else if(i % 15625 == 0){
            res /= 1000000;
        }
        else if(i % 3125 == 0){
            res /= 100000;
        }
        else if(i % 625 == 0){
            res /= 10000;
        }
        else if(i % 125 == 0){
            res /= 1000;
        }
        else if(i % 25 == 0){
            res /= 100;
        }
        else if(i % 5 == 0){
            res /= 10;
        }
        res %= 1000000000;
        ans.push_back(res);
    }

    int st = lower_bound(fives, fives + 2'000'000, cnt) - fives;
    for(int i = st; i < st + 5; i += 1){
        if(num % 10000 == ans[i] % 10000){
            // cout << ans[i] << '\n';
            cout << i << '\n';
            return 0;
        }
    }

    // for(auto &x : ans){
    //     cout << x << ' ';
    // }
    // cout << '\n';

    return 0;
}

// 1 2 6 24 12 72 04 32 88 88
// 68 16 08 12 68 88 96 28 32 64