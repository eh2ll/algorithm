#include <bits/stdc++.h>

using namespace std;

int M, N, L, pos[100005];
vector<pair<int, int>> V;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> L;
    for(int i = 0; i < M; i += 1){
        cin >> pos[i];
    }
    sort(pos, pos + M);

    for(int i = 0; i < N; i += 1){
        int a, b; cin >> a >> b;
        V.push_back({a, b});
    }

    int res = 0;
    for(auto [cx, cy] : V){
        int lo = 0, hi = M - 1;
        while(hi - lo >= 3){
            int p = (2 * lo + hi) / 3;
            int q = (lo + 2 * hi) / 3;

            int len1 = abs(cx - pos[p]) + cy;
            int len2 = abs(cx - pos[q]) + cy;

            if(len1 >= len2) lo = p;
            else hi = q;
        }

        for(int i = lo; i <= hi; i += 1){
            if(abs(cx - pos[i]) + cy <= L){
                res += 1;
                break;
            }
        }
    }

    cout << res << '\n';

    return 0;
}