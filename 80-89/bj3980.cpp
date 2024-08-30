#include <bits/stdc++.h>
using namespace std;

int T;
vector<pair<int, int>> adj[11];
int visited[11];
int tot;

void dfs(int x, int sum){
    if(x == 11){
        tot = max(tot, sum);
        return;
    }

    for(auto cur : adj[x]){
        if(visited[cur.second] == 1) continue;
        visited[cur.second] = 1;
        dfs(x + 1, sum + cur.first);
        visited[cur.second] = 0;
    }

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T--){
        for(int i = 0; i < 11; i += 1){
            for(int j = 0; j < 11; j += 1){
                int x; cin >> x;
                if(!x) continue;
                adj[i].push_back({x, j});
            }
        }

        tot = 0;
        dfs(0, 0);
        cout << tot << '\n';

        for(int i = 0; i < 11; i += 1) adj[i].clear();
    }

    return 0;
}