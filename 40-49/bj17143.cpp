#include <bits/stdc++.h>

using namespace std;

int R, C, M;
tuple<int, int, int, int, int> shark[10004];
int bor[102][102];
int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;
    for(int i = 1; i <= M; i += 1){
        int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
        shark[i] = {r, c, s, d, z};
        bor[r][c] = i;
    }

    int res = 0;
    for(int j = 1; j <= C; j += 1){
        
        // for(int i1 = 1; i1 <= R; i1 += 1){
        //     for(int j1 = 1; j1 <= C; j1 += 1){
        //         cout << bor[i1][j1] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        for(int i = 1; i <= R; i += 1){
            if(bor[i][j]){
                auto [r, c, s, d, z] = shark[bor[i][j]];
                res += z;
                shark[bor[i][j]] = {-1, -1, -1, -1, -1};
                break;
            }
        }

        memset(bor, 0, sizeof(bor));

        for(int i = 1; i <= M; i += 1){
            auto [r, c, s, d, z] = shark[i];
            int flag = 0;
            // cout << i << ": " << r << ' ' << c << ' ' << s << ' ' << d << ' ' << z << '\n';

            if(r < 0) continue;
            int d1 = (dx[d] * s) % (2 * R - 2);
            // cout << "d1 dx[d] s R " << d1 << ' ' << dx[d] << ' ' << s << ' ' << R << '\n';
            int nx = r + d1;
            for(int k = 0; k < 2; k += 1){
                if(nx <= 0){
                    nx *= -1;
                    nx += 2;
                    flag += 1;
                }
                else if(nx > R){
                    nx = 2 * R - nx;
                    flag += 1;
                }
            }
            
            int d2 = (dy[d] * s) % (2 * C - 2);
            // cout << "d2 dx[d] s R " << d2 << ' ' << dy[d] << ' ' << s << ' ' << C << '\n';
            int ny = c + d2;
            for(int k = 0; k < 2; k += 1){   
                if(ny <= 0){
                    ny *= -1;
                    ny += 2;
                    flag += 1;
                }
                else if(ny > C){
                    ny = 2 * C - ny;
                    flag += 1;
                }
            }
            
            if(bor[nx][ny]){
                auto [n1, n2, n3, n4, n5] = shark[bor[nx][ny]];
                if(n5 > z){
                    shark[i] = {-1, -1, -1, -1, -1};
                    continue;
                }
                else{
                    shark[bor[nx][ny]] = {-1, -1, -1, -1, -1};
                }
            }

            // cout << "flag " << flag << '\n';
            while(flag--) d = (d & 1) ? d + 1 : d - 1; 
            bor[nx][ny] = i;
            shark[i] = {nx, ny, s, d, z};

            // cout << i << ": " << r << ' ' << c << ' ' << d << ' ' << s << ' ' << z << '\n';
            // cout << i << ": " << nx << ' ' << ny << " d:" << d << " d1:" << d1 << " d2:" << d2 << '\n';
            // cout << '\n';
        }
    }

    cout << res << '\n';

    return 0;
}