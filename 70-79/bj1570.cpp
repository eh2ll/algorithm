#include <bits/stdc++.h>

using namespace std;

int N, sx, sy, mx, my;
vector<string> V;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> sx >> sy >> mx >> my;
    
    if(sx > mx || sy > my){
        cout << -1 << '\n';
    }
    else if((mx - sx) + (my - sy) <= N){
        for(int i = 0; i < mx - sx; i += 1) cout << 'R';
        for(int i = 0; i < my - sy; i += 1) cout << 'U';
        for(int i = 0; i < N - (mx - sx) - (my - sy); i += 1) cout << 'R';
    }
    else{
        for(int r = N; r >= 0; r -= 1){
            string tmp = "";
            int tr = r;
            int tu = N - r;
            
            int cnt = 0;
            if(tr == 0) cnt = (my - sy) / tu;
            else if(tu == 0) cnt = (mx - sx) / tr;
            else cnt = min((mx - sx) / tr, (my - sy) / tu);

            int dx = (mx - sx) - tr * cnt;
            int dy = (my - sy) - tu * cnt;

            // cout << cnt << '\n';
            // cout << tr << ' ' << tu << ' ' << dx << ' ' << dy << '\n';

            if(tr < dx || tu < dy) continue;
            else{
                for(int i = 0; i < dx; i += 1) tmp += 'R';
                for(int i = 0; i < dy; i += 1) tmp += 'U';
                for(int i = 0; i < tr - dx; i += 1) tmp += 'R';
                for(int i = 0; i < tu - dy; i += 1) tmp += 'U';
            }
            // cout << tmp << '\n';
            V.push_back(tmp);
        }

        if(V.empty()) cout << -1 << '\n';
        else{
            sort(V.begin(), V.end());
            cout << V[0] << '\n';
        }
    }

    return 0;
}