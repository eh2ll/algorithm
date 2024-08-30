#include <bits/stdc++.h>

using namespace std;

int TC, N;
map<string, int> mp;
vector<int> p(200005, -1);
int cnt[200005];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v){
    u = find(u), v = find(v);
    if(u < v){
        p[v] = u;
        cnt[u] += cnt[v];
    }
    else if(u > v){
        p[u] = v;
        cnt[v] += cnt[u];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        fill(p.begin(), p.end(), -1);
        fill(cnt, cnt + 200005, 1);
        mp.clear();

        cin >> N;

        int num = 1;
        for(int i = 0; i < N; i += 1){
            string a, b; cin >> a >> b;
            if(mp[a] == 0) mp[a] = num++;
            if(mp[b] == 0) mp[b] = num++;

            int u = mp[a];
            int v = mp[b];
            merge(u, v);
            
            cout << cnt[find(u)] << '\n';
        }
    }

    return 0;
}