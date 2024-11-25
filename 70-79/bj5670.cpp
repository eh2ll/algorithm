// barkingdog

#include <bits/stdc++.h>

using namespace std;

int N;
const int root = 1, mx = 1e6 + 5;
int unused = 2;
string arr[100005];
vector<pair<int, int>> nxt[mx];
int chk[mx];
long double res;

int child(int node, char c){
    for(auto [id, tmp] : nxt[node]){
        if(c == tmp) return id;
    }
    return -1;
}

void insert(string& s){
    int cur = root;
    for(auto c : s){
        int ch = child(cur, c);
        if(ch == -1){
            ch = unused;
            nxt[cur].push_back({unused++, c});
        }
        cur = ch;
    }
    chk[cur] = 1;
}

void find(int cur, int cnt){
    if(chk[cur]){
        cnt += 1;
        res += cnt;
    }
    else if(nxt[cur].size() > 1){
        cnt += 1;
    }
    for(auto [pos, _] : nxt[cur]){
        find(pos, cnt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> N){
        for(int i = 0; i < 1e6 + 5; i += 1) nxt[i].clear();
        memset(chk, 0, sizeof(chk));
        unused = root + 1;
        res = 0;

        for(int i = 0; i < N; i += 1){
            cin >> arr[i];
            insert(arr[i]);
        }

        for(auto [idx, _] : nxt[root]){
            find(idx, 0);
        }

        cout << fixed;
        cout.precision(2);
        cout << res / N << '\n';
    }

    return 0;
}