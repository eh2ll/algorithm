#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int TC, N, M, arr[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TC;
    while(TC--){
        memset(arr, 0, sizeof(arr));
        cin >> N >> M;
        queue<pii> Q;
        priority_queue<int> PQ;
        for(int i = 0; i < N; i += 1){
            int x; cin >> x;
            Q.push({x, i});
            PQ.push(x);
        }

        int cnt = 1;
        while(!Q.empty()){
            if(PQ.top() == Q.front().first){
                if(Q.front().second == M){
                    cout << cnt << '\n';
                    break;
                }
                Q.pop();
                PQ.pop();
                cnt += 1;
            }
            else{
                Q.push(Q.front());
                Q.pop();
            }
        }
    }

    return 0;
}