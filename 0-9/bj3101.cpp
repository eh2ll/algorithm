#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
ll x = 1, y = 1, res = 1;
map<char, int> mp;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    mp['U'] = 0;
    mp['D'] = 1;
    mp['L'] = 2;
    mp['R'] = 3;

    string s; cin >> s;
    for(int i = 0; i < s.size(); i += 1){
        x += dx[mp[s[i]]];
        y += dy[mp[s[i]]];

        if(x + y > N + 1){
            ll rx = N - x + 1, ry = N - y + 1;
            if((rx + ry) & 1){
                ll cnt = (rx + ry - 2) * (rx + ry - 1) / 2;
                res += 1LL * N * N + 1 - cnt - rx;
            }
            else{
                ll cnt = (rx + ry - 2) * (rx + ry - 1) / 2;
                res += 1LL * N * N + 1 - cnt - ry;
            }
        }
        else{
            if((x + y) & 1){
                ll cnt = (x + y - 2) * (x + y - 1) / 2;
                res += cnt + x;
            }
            else{
                ll cnt = (x + y - 2) * (x + y - 1) / 2;
                res += cnt + y;
            }
        }
    }

    cout << res << '\n';

    return 0;
}