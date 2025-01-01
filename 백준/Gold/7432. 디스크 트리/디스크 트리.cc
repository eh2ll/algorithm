#include <bits/stdc++.h>

using namespace std;

int N;
map<string, int> nxt[30000];
int root = 1, unused = 2;

void insert(vector<string>& V){
    int cur = root;
    for(auto c : V){
        if(!nxt[cur][c]) nxt[cur][c] = unused++;
        cur = nxt[cur][c];
    }
}

void dfs(int cur, int d){
    for(auto nx : nxt[cur]){
        string lev = "";
        for(int i = 0; i < d; i += 1){
            lev += " ";
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
        string s; cin >> s;
        
        vector<string> V;
        string tmp = "";
        for(int i = 0; i < s.size(); i += 1){
            if(s[i] == '\\'){
                V.push_back(tmp);
                tmp = "";
            }
            else{
                tmp += s[i];
            }
        }
        V.push_back(tmp);
        
        insert(V);
    }

    dfs(root, 0);

    return 0;
}