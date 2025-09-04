// bcc. kks227

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M, cnt, root;
int dfsn[10'004];
vector<int> g[10'004];
stack<pii> S;
vector<vector<pii>> bcc;
set<int> cut;

int dfs(int cur, int pre){
    dfsn[cur] = ++cnt;
    int ret = dfsn[cur];
    int child = 0;

    for(auto nxt : g[cur]){
        if(nxt == pre) continue;

        if(dfsn[cur] > dfsn[nxt]) S.push({cur, nxt});
        if(dfsn[nxt] > 0) ret = min(ret, dfsn[nxt]);
        else{
            int tmp = dfs(nxt, cur);
            ret = min(ret, tmp);

            if(tmp >= dfsn[cur]){
                vector<pii> curbcc;
                while(!S.empty() && S.top() != pii(cur, nxt)){
                    curbcc.push_back(S.top());
                    S.pop();
                }
                curbcc.push_back(S.top());
                S.pop();
                bcc.push_back(curbcc);
            }

            if(cur != root && tmp >= dfsn[cur]) cut.insert(cur);
            child += 1;
        }
    }
    
    if(cur == root && child >= 2) cut.insert(cur);

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    for(int i = 1; i <= N; i += 1){
        if(dfsn[i] == 0){
            root = i;
            dfs(i, 0);
        }
    }

    cout << cut.size() << '\n';
    for(auto i : cut) cout << i << ' ';
    cout << '\n';

    return 0;
}