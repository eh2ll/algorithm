#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int N, M, K;
int bor[15][15], inp[15][15];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> adj[15][15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 15; i += 1) fill(bor[i], bor[i] + 15, 5);

    cin >> N >> M >> K;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            cin >> inp[i][j];
        }
    }

    for(int i = 0; i < M; i += 1){
        int x, y, z; cin >> x >> y >> z;
        adj[x][y].push_back(z);
    }

    while(K--){
        for(int i = 1; i <= N; i += 1){
            for(int j = 1; j <= N; j += 1){
                if(!adj[i][j].size()) continue;

                int dtr = 0;
                vector<int> tmp;
                sort(adj[i][j].begin(), adj[i][j].end());

                for(int k = 0; k < adj[i][j].size(); k += 1){
                    int age = adj[i][j][k];
                    if(bor[i][j] < age){
                        dtr += age / 2;
                    }
                    else{
                        bor[i][j] -= age;
                        tmp.push_back(age + 1);
                    }
                }

                adj[i][j].clear();
                for(int k = 0; k < tmp.size(); k += 1){
                    adj[i][j].push_back(tmp[k]);
                }
                bor[i][j] += dtr;
            }
        }

        for(int i = 1; i <= N; i += 1){
            for(int j = 1; j <= N; j += 1){
                if(!adj[i][j].size()) continue;

                for(int k = 0; k < adj[i][j].size(); k += 1){
                    if(adj[i][j][k] % 5 != 0) continue;
                    for(int dir = 0; dir < 8; dir += 1){
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        if(nx < 1 || ny < 1 || nx > N || ny > N) continue;

                        adj[nx][ny].push_back(1);
                    }
                }
            }
        }

        for(int i = 1; i <= N; i += 1){
            for(int j = 1; j <= N; j += 1){
                bor[i][j] += inp[i][j];
            }
        }

        // for(int i = 1; i <= N; i += 1){
        //     for(int j = 1; j <= N; j += 1){
        //         cout << bor[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // for(auto cur : adj) cout << cur.Y.X << ' ' << cur.Y.Y << '\n';
    }

    int tot = 0;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            tot += adj[i][j].size();
        }
    }

    cout << tot << '\n';

    return 0;
}