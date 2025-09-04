#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        map<int, int> mp;
        vector<int> iter, num(6);
        bool check[10] = {0};
        int idx = 0;
        for(int i = 0; i < 6; i += 1){
            if(s[i] == 'x') mp[idx++] = i;
            else{
                num[i] = s[i] - '0';
                check[s[i] - '0'] = 1;
            }
        }
        for(int i = 1; i <= 6; i += 1){
            if(!check[i]) iter.push_back(i);
        }

        int mn = 0x3f3f3f3f;
        vector<int> ans(6);
        do{
            for(int i = 0; i < iter.size(); i += 1){
                num[mp[i]] = iter[i];
            }

            int sum = 0;
            sum += abs(num[0] - num[2]);
            sum += abs(num[1] - num[2]);
            sum += abs(num[2] - num[3]);
            sum += abs(num[3] - num[4]);
            sum += abs(num[2] - num[5]);

            if(sum < mn){
                mn = sum;
                ans = num;
            }
        }while(next_permutation(iter.begin(), iter.end()));

        for(int i = 0; i < 6; i += 1) cout << ans[i];
        cout << '\n';
    }

    return 0;
}