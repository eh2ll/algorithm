#include <bits/stdc++.h>

using namespace std;

int N, M;
map<string, int> mp;

bool cmp(const string& a, const string& b){
    if(mp[a] == mp[b]){
        if(a.size() == b.size()){
            return a < b;
        }
        else return a.size() > b.size();
    }
    else return mp[a] > mp[b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        string s; cin >> s;
        if(s.size() < M) continue;
        mp[s] += 1;
    }

    vector<string> V;
    for(auto cur : mp) V.push_back(cur.first);

    sort(V.begin(), V.end(), cmp);

    for(auto cur : V) cout << cur << '\n';

    return 0;
}