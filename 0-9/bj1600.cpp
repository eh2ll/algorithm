#include <bits/stdc++.h>

using namespace std;
using tii = tuple<int, int, int>;

int K, W, H;
int bor[202][202];
int dx1[4] = {1, 0, -1, 0}, dy1[4] = {0, 1, 0, -1};
int dx2[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dy2[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> W >> H;
    for(int i = 0; i < H; i += 1){
        for(int j = 0; j < W; j += 1){
            cin >> bor[i][j];
        }
    }

    queue<pii> Q;
    Q.push({0, 0});
    while(!Q.empty()){
        auto [cx, cy] = Q.front(); Q.pop();

    }
}