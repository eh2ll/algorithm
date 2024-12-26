// justicehui

#include <bits/stdc++.h>

using namespace std;

int N, st;
int bor[1003][1003];
map<int, map<int, int>> mp;

bool chk(){
    for(int i = 1; i <= N; i += 1){
        int cnt = 0;
        for(auto [k, v] : mp[i]){
            cnt += v;
        }

        if(cnt & 1) return 0;
        if(!st && cnt > 0) st = i;
    }
    return 1;
}

void dfs(int cur){
    while(!mp[cur].empty()){
        auto [nxt, cnt] = *mp[cur].begin();
        mp[nxt][cur] -= 1;
        mp[cur][nxt] -= 1;
        if(mp[nxt][cur] == 0){
            mp[nxt].erase(cur);
            mp[cur].erase(nxt);
        }
        dfs(nxt);
    }
    cout << cur << ' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            int x; cin >> x;
            if(x) mp[i][j] = x;
        }
    }

    if(!chk()) cout << -1 << '\n';
    else{
        dfs(st);
        cout << '\n';
    }

    return 0;
}