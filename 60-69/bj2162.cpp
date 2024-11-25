#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
using ll = long long;
using point = pair<ll, ll>;

int N;

struct nod
{
    point p1, p2;
};

nod g[3003];
int p[3003], r[3003];

int ccw(point a, point b, point c){
    ll res = a.X * b.Y + b.X * c.Y + c.X * a.Y;
    res -= a.Y * b.X + b.Y * c.X + c.Y * a.X;

    return (res > 0) - (res < 0);
}

bool cross(point a, point b, point c, point d){
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void mrg(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;
    if(u > v) swap(u, v);
    p[v] = u;
    r[u] += r[v];
    r[v] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(p, -1, sizeof(p));
    fill(r, r + 3003, 1);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> g[i].p1.X >> g[i].p1.Y >> g[i].p2.X >> g[i].p2.Y;
        point A = {g[i].p1.X, g[i].p1.Y};
        point B = {g[i].p2.X, g[i].p2.Y};

        for(int j = 0; j < i; j += 1){
            auto [C, D] = g[j];
            if(cross(A, B, C, D)) mrg(i, j);
        }
    }

    int cnt = 0, mx = 0;
    for(int i = 0; i < N; i += 1){
        if(r[i]) cnt += 1;
        mx = max(mx, r[i]);
    }

    cout << cnt << '\n' << mx << '\n';

    return 0;
}