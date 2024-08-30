#include <bits/stdc++.h>

using namespace std;

int TC, N, cnt, arr[100005], vis[100005], fin[100005];

void dfs(int x){
    vis[x] = 1;

    if(vis[arr[x]]){
        if(!fin[arr[x]]){
            for(int tmp = arr[x]; tmp != x; tmp = arr[tmp]) cnt += 1;
            cnt += 1;
        }
    }
    else dfs(arr[x]);

    fin[x] = 1;

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        memset(fin, 0, sizeof(fin));
        cnt = 0;
        
        cin >> N;
        for(int i = 1; i <= N; i += 1){
            cin >> arr[i];
        }

        for(int i = 1; i <= N; i += 1){
            if(vis[i]) continue;
            dfs(i);
        }

        cout << N - cnt << '\n';
    }

    return 0;
}