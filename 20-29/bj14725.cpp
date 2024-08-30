// barkingdog trie

#include <bits/stdc++.h>

using namespace std;

int N;
const int inf = 15004;
map<string, int> nxt[inf];
int root = 1;
int unused = 2;

void insert(vector<string> V){
    int cur = root;
    for(auto c : V){
        if(!nxt[cur][c]){
            nxt[cur][c] = unused++;
        }
        cur = nxt[cur][c];
    }
}

void dfs(int cur, int d){
    for(auto nx : nxt[cur]){
        string lev;
        for(int i = 0; i < d; i += 1){
            lev += "--";
        }
        cout << lev << nx.first << '\n';
        dfs(nx.second, d + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int M; cin >> M;
        vector<string> V;
        V.resize(M);
        for(int j = 0; j < M; j += 1){
            cin >> V[j];
        }
        insert(V);
    }
    dfs(1, 0);

    return 0;
}