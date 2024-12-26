#include <bits/stdc++.h>

using namespace std;

int Q, M;
stack<int> S;
vector<int> arr[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> Q >> M;
    for(int i = 0; i < M; i += 1) arr[i].push_back(-1);
    for(int i = 0; i < Q; i += 1){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x;
            S.push(x % M);
            arr[x % M].push_back(S.size());
        }
        else if(op == 2){
            if(S.empty()) continue;
            arr[S.top()].pop_back();
            S.pop();
        }
        else{
            int flag = 0x3f3f3f3f;
            for(int j = 0; j < M; j += 1){
                flag = min(flag, arr[j].back());
            }
            
            if(flag == -1) cout << -1 << '\n';
            else cout << S.size() - flag + 1 << '\n';
        }
    }

    return 0;
}