#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1000000;
int N;
vector<ll> tree;

ll query(int node, int start, int end, int cnt){
    if(start == end) return start;

    if(tree[node * 2] >= cnt) return query(node * 2, start, (start + end) / 2, cnt);
    else return query(node * 2 + 1, (start + end) / 2 + 1, end, cnt - tree[node * 2]);
}

void update(int node, int start, int end, int idx, ll diff){
    if(idx < start || end < idx) return;

    tree[node] += diff;

    if(start != end){
        update(node * 2, start, (start + end) / 2, idx, diff);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H = (int)ceil(log2(inf));
    int S = (1 << (1 + H));
    tree.resize(S);

    cin >> N;
    while(N--){
        int a, b, c; cin >> a;
        if(a == 1){
            cin >> b;
            ll pos = query(1, 1, inf, b);
            cout << pos << '\n';
            update(1, 1, inf, pos, -1);
        }
        else{
            cin >> b >> c;
            update(1, 1, inf, b, c);
        }
    }

    return 0;
}