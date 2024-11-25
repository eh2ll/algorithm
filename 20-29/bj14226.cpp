#include <bits/stdc++.h>

using namespace std;

int N, dis[1003][1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N;
    queue<pair<int, int>> Q;
    Q.push({1, 0});
    dis[1][0] = 0;

    while(!Q.empty()){
        auto [d, c] = Q.front(); Q.pop();

        if(d == N){
            cout << dis[d][c] << '\n';
            return 0;
        }

        if(d > 0 && d < 1001){
            if(!dis[d][d]){
                dis[d][d] = dis[d][c] + 1;
                Q.push({d, d});
            }
            if(!dis[d - 1][c]){
                dis[d - 1][c] = dis[d][c] + 1;
                Q.push({d - 1, c});
            }
        }
        if(c > 0 && d + c < 1001){
            if(!dis[d + c][c]){
                dis[d + c][c] = dis[d][c] + 1;
                Q.push({d + c, c});
            }
        }
    }

    return 0;
}