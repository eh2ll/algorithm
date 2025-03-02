#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;
bool chk[2003];
map<int, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr.resize(N);
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
        mp[arr[i]] += 1;
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for(int i = 0; i < (int)arr.size(); i += 1){
        for(int j = i; j < (int)arr.size(); j += 1){
            int u = arr[i], v = arr[j];
            int it = lower_bound(arr.begin(), arr.end(), u + v) - arr.begin();
            
            if(u + v != arr[it]) continue;
            
            if(chk[it]) continue;
            if(i == j && mp[i] < 2) continue;

            if(u + v != u && u + v != v) chk[it] = 1;
            else{
                if(u == 0 && v == 0 && mp[u] < 3) continue;
                
                if(u + v == u && mp[u] > 1) chk[it] = 1;
                else if(u + v == v && mp[v] > 1) chk[it] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < (int)arr.size(); i += 1) if(chk[i]) cnt += mp[arr[i]];

    cout << cnt << '\n';

    return 0;
}