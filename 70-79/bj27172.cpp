#include <bits/stdc++.h>

using namespace std;

int N, arr[100005];
map<int, int> mp;
bool vis[1000006];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
        mp[arr[i]] = 0;
        vis[arr[i]] = 1;
    }

    for(auto cur : mp){
        for(int i = 2; cur.first * i <= 1000000; i += 1){
            if(vis[cur.first * i]){
                mp[cur.first * i] -= 1;
                mp[cur.first] += 1;
            }
        }
    }

    for(int i = 0; i < N; i += 1){
        cout << mp[arr[i]] << ' ';
    }
    cout << '\n';

    return 0;
}