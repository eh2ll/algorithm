#include <bits/stdc++.h>

using namespace std;
using pci = pair<char, int>;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

int N, K;
pci bor[1003];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// set<tii> arr;
map<pii, vector<int>> arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i += 1){
        cin >> bor[i].first >> bor[i].second;
    }

    map<pii, int> mp;
    int cx = 0, cy = 0, cnt = 0;
    for(int i = 0; i < N; i += 1){
        auto [c, x] = bor[i];
        
        int idx = -1;
        if(c == 'N') idx = 0;
        else if(c == 'E') idx = 1;
        else if(c == 'S') idx = 2;
        else if(c == 'W') idx = 3;

        for(int dir = 1; dir <= x; dir += 1){
            int nx = cx + dx[idx] * dir;
            int ny = cy + dy[idx] * dir;
            if(mp.find({nx, ny}) != mp.end()){                        
                // arr.insert({nx, ny, mp[{nx, ny}]});
                // arr.insert({nx, ny, cnt + dir});
                auto &T = arr[{nx, ny}];
                if(T.empty()) T.push_back(mp[{nx, ny}]);
                T.push_back(cnt + dir);
                mp[{nx, ny}] = cnt + dir;
            }
            else mp[{nx, ny}] = cnt + dir;
        }

        cx += dx[idx] * x;
        cy += dy[idx] * x;
        cnt += x;
    }        

    // for(auto [x, y, cost] : arr) cout << x << ' ' << y << ' ' << cost << '\n';

    int st = 0, en = 1000001;
    while(st + 1 < en){
        int mid = (st + en + 1) / 2;
        map<pii, int> vis;
        int res = 0;
        for(auto &[key, T] : arr){
            int htime = T[0];
            for(int i = 1; i < (int)T.size(); i += 1){
                if(T[i] - htime >= mid){
                    res += 1;
                    htime = T[i];
                }
            }
        }

        if(res >= K) st = mid;
        else en = mid;
    }

    if(st != 0 && en != 1000001) cout << st << '\n';
    else cout << -1 << '\n';

    return 0;
}