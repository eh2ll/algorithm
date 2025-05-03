#include <bits/stdc++.h>

using namespace std;

int N, A[52];
int par[102];
bool chk[102];
vector<int> adj[102];

bool isp[2'005];
vector<int> pr;
void sieve(){
    for(int i = 2; i <= 2000; i += 1){
        if(!isp[i]) pr.push_back(i);
        for(auto j : pr){
            if(i * j > 2000) break;
            isp[i * j] = 1;
            if(i % j == 0) break;
        }
    }
}

int match(int cur){
    if(cur == 1 || cur == par[51]) return 0;
    for(auto nxt : adj[cur]){
        if(chk[nxt]) continue;
        chk[nxt] = 1;
        if(par[nxt] == -1 || match(par[nxt])){
            par[nxt] = cur;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        cin >> A[i];
        for(int j = 1; j < i; j += 1){
            if(!isp[A[i] + A[j]]){
                adj[i].push_back(j + 50);
                adj[j].push_back(i + 50);
            }
        }
    }

    vector<int> ans;
    for(auto nxt : adj[1]){
        memset(par, -1, sizeof(par));
        par[nxt] = 1;
        par[51] = nxt - 50;
        
        int res = 2;
        for(int i = 2; i <= N; i += 1){
            memset(chk, 0, sizeof(chk));
            if(match(i)) res += 1;
        }

        // cout << res << '\n';
        if(res == N) ans.push_back(A[nxt - 50]);
    }

    if(ans.empty()) cout << -1 << '\n';
    else{
        sort(ans.begin(), ans.end());
        for(auto c : ans) cout << c << ' ';
        cout << '\n';
    }

    return 0;
}