#include <bits/stdc++.h>

using namespace std;
using tii = tuple<int, int, int, int>;

int N;
vector<tii> arr;

int chk13(int a, int b, int c, int d){
    for(auto [w, x, y, z] : arr){
        int cnt = 0;
        if(a == w || a == x || a == y || a == z) cnt += 1;
        if(b == w || b == x || b == y || b == z) cnt += 1;
        if(c == w || c == x || c == y || c == z) cnt += 1;
        if(d == w || d == x || d == y || d == z) cnt += 1;

        if(cnt == 4) return -1;
        if(cnt & 1) return 0;
    }
    return 1;
}

int chk22(int a, int b, int c, int d){
    for(auto [w, x, y, z] : arr){
        int cnt = 0;
        if(a == w || a == x || a == y || a == z) cnt += 1;
        if(b == w || b == x || b == y || b == z) cnt += 1;
        if(c == w || c == x || c == y || c == z) cnt += 1;
        if(d == w || d == x || d == y || d == z) cnt += 1;

        if(cnt == 2){
            map<int, int> mp;
            mp[a] = mp[b] = mp[c] = mp[d] = 1;
            mp[w] += 1;
            mp[x] += 1;
            mp[y] += 1;
            mp[z] += 1;
            int bor[4];
            int tmp = 0;
            for(auto [k, v] : mp) if(v & 1) bor[tmp++] = k;
            for(auto [n1, n2, n3 ,n4] : arr){
                if(n1 == bor[0] && n2 == bor[1] && n3 == bor[2] && n4 == bor[3]) return 0;
            }
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ret1 = chk13(a, b, c, d);
        int ret2 = chk22(a, b, c, d);
        // cout << ret1 << ' ' << ret2 << '\n';
        if(ret1 == -1) continue;
        else if(ret1 == 0 || ret2 == 0){
            cout << "You're gonna die!" << '\n';
            return 0;
        }
        else{
            int bor[4];
            bor[0] = a;
            bor[1] = b;
            bor[2] = c;
            bor[3] = d;
            sort(bor, bor + 4);
            arr.push_back({bor[0], bor[1], bor[2], bor[3]});
        }
    }

    cout << "Hmm..." << '\n';

    return 0;
}