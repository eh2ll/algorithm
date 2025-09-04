#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    deque<pair<int, int>> inp;
    for(int i = 0; i < N; i += 1){
        int a, b; cin >> a >> b;
        inp.push_back({a, b});
    }
    while(inp.front().second > 0){
        inp.push_back(inp.front());
        inp.pop_front();
    }
    inp.push_back(inp.front());

    vector<pair<int, int>> A;
    int pre = -1, l = 0, r = 0;
    while(!inp.empty()){
        auto [a, b] = inp.front(); inp.pop_front();
        if(pre < 0 && b > 0){
            l = a;
        }
        else if(pre > 0 && b < 0){
            r = a;
            if(l > r) swap(l, r);
            A.push_back({l, r});
        }
        pre = b;
    }
    sort(A.begin(), A.end());

    int cnt1 = 0, cnt2 = 0;
    stack<int> en;
    map<int, int> mp;
    for(auto [l, r] : A){
        while(!en.empty() && en.top() < l){
            en.pop();
        }
        if(en.empty()){
            cnt1 += 1;
        }
        else{
            mp[en.top()] += 1;
        }
        en.push(r);
    }
    
    for(auto [l, r] : A) cnt2 += (!mp[r]) ? 1 : 0;

    cout << cnt1 << ' ' << cnt2 << '\n';

    return 0;
}