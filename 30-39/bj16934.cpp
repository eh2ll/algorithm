#include <bits/stdc++.h>

using namespace std;

int N;
const int inf = 100000 * 10 + 5;
const int root = 1;
int unused = 2;
int nxt[inf][26];
map<string, int> cnt;

int c2i(char c){
    return c - 'a';
}

void insert(string s){
    int cur = root;
    for(auto c : s){
        if(nxt[cur][c2i(c)] == 0){
            nxt[cur][c2i(c)] = unused++;
        }
        cur = nxt[cur][c2i(c)];
    }
}

string find(string s){
    int cur = root;
    string tmp = "";
    for(auto c : s){
        tmp += c;
        if(nxt[cur][c2i(c)] == 0) return tmp;
        cur = nxt[cur][c2i(c)];
    }
    if(cnt[s] > 1) tmp += to_string(cnt[s]);
    return tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        string s; cin >> s;
        cnt[s] += 1;
        cout << find(s) << '\n';
        insert(s);
    }

    return 0;
}