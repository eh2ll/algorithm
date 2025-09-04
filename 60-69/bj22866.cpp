#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> A(N + 1);
    for(int i = 1; i <= N; i += 1){
        cin >> A[i];
    }

    vector<pair<int, int>> ans(N + 1, {0, 0x3f3f3f3f});

    stack<pair<int, int>> S1;
    for(int i = 1; i <= N; i += 1){
        if(S1.empty() || S1.top().first > A[i]){
            if(!S1.empty()){
                ans[i].first += S1.size();
                ans[i].second = min(ans[i].second, S1.top().second);
            }
            S1.push({A[i], i});
        }
        else{
            while(!S1.empty() && S1.top().first <= A[i]){
                S1.pop();
            }
            if(!S1.empty()){
                ans[i].first += S1.size();
                ans[i].second = S1.top().second;
            }
            S1.push({A[i], i});
        }
    }

    stack<pair<int, int>> S2;
    for(int i = N; i >= 1; i -= 1){
        if(S2.empty() || S2.top().first > A[i]){
            if(!S2.empty()){
                ans[i].first += S2.size();
                if(ans[i].second == 0x3f3f3f3f){
                    ans[i].second = S2.top().second;
                }
                else{
                    ans[i].second = (i - ans[i].second <= S2.top().second - i) ? ans[i].second : S2.top().second;
                }
            }
            S2.push({A[i], i});
        }
        else{
            while(!S2.empty() && S2.top().first <= A[i]){
                S2.pop();
            }
            if(!S2.empty()){
                ans[i].first += S2.size();
                if(ans[i].second == 0x3f3f3f3f){
                    ans[i].second = S2.top().second;
                }
                else{
                    ans[i].second = (i - ans[i].second <= S2.top().second - i) ? ans[i].second : S2.top().second;
                }
            }
            S2.push({A[i], i});
        }
    }

    for(int i = 1; i <= N; i += 1){
        int cnt = ans[i].first;
        if(!cnt){
            cout << 0 << '\n';
        }
        else{
            int mn = ans[i].second;
            cout << cnt << ' ' << mn << '\n';
        }
    }

    return 0;
}