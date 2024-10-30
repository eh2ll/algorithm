#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;
using t5i = tuple<int, int, int, int, int>;

int N, M;
string bor[11];
pii red, blue, goal;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i += 1){
        cin >> bor[i];
        for(int j = 0; j < M; j += 1){
            if(bor[i][j] == 'R'){
                red = {i, j};
                bor[i][j] = '.';
            }
            else if(bor[i][j] == 'B'){
                blue = {i, j};
                bor[i][j] = '.';
            }
            else if(bor[i][j] == 'O'){
                goal = {i, j};
            }
        }
    }

    // for(int i = 0; i < 5; i += 1) cout << bor[i] << '\n';

    queue<t5i> Q;
    Q.push({red.X, red.Y, blue.X, blue.Y, 0});
    while(!Q.empty()){
        auto [rx, ry, bx, by, cost] = Q.front(); Q.pop();

        // cout << "Q " << rx << '.' << ry << ' ' << bx << '.' << by << ' ' << cost << '\n';

        for(int dir = 0; dir < 4; dir += 1){
            int nrx = rx, nry = ry;
            int nbx = bx, nby = by;
            int moveA = 1, moveB = 1;
            int redin = 0, bluein = 0;
            while(moveA | moveB){
                // cout << (bor[nrx + dx[dir]][nry + dy[dir]] != '#') << (nrx + dx[dir] != nbx) << (nry + dy[dir] != nby) << '\n';
                if((bor[nrx + dx[dir]][nry + dy[dir]] != '#') && !((nrx + dx[dir] == nbx) && (nry + dy[dir] == nby))){
                    if(bor[nrx + dx[dir]][nry + dy[dir]] == 'O'){
                        redin = 1;
                        nrx = nbx - dx[dir];
                        nry = nby - dy[dir];
                    }
                    nrx += dx[dir];
                    nry += dy[dir];
                    moveA = 1;
                }
                else moveA = 0;

                // cout << (bor[nbx + dx[dir]][nby + dy[dir]] != '#') << (nbx + dx[dir] != nrx) << (nby + dy[dir] != nry) << '\n';
                if((bor[nbx + dx[dir]][nby + dy[dir]] != '#') && !((nbx + dx[dir] == nrx) && (nby + dy[dir] == nry))){
                    if(bor[nbx + dx[dir]][nby + dy[dir]] == 'O'){
                        bluein = 1;
                        nbx = nrx - dx[dir];
                        nby = nry - dy[dir];
                    }
                    nbx += dx[dir];
                    nby += dy[dir];
                    moveB = 1;
                }
                else moveB = 0;
                // cout << '(' << redin << ' ' << bluein << ") ";
                // cout << bor[nrx + dx[dir]][nry + dy[dir]] << ' ' << bor[nbx + dx[dir]][nby + dy[dir]] << '\n';
                // cout << nrx << '.' << nry << ' ' << nbx << '.' << nby << ' ' << moveA << ' ' << moveB << '\n';            
                if(bluein) break;
            }

            // cout << nrx << ' ' << nry << ' ' << nbx << ' ' << nby << '\n';
            // cout << "rb " << redin << ' ' << bluein << '\n';

            if(bluein) continue;
            if(redin) {
                cout << cost + 1 << '\n';
                return 0;
            }

            if(cost + 1 >= 10) continue;
            if(!((nrx == rx) && (nry == ry)) || !((nbx == bx) && (nby == by))) Q.push({nrx, nry, nbx, nby, cost + 1});
        }
    }

    cout << -1 << '\n';

    return 0;
}