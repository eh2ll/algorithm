// pill27211, vkdldjvkdnj

#include <bits/stdc++.h>

using namespace std;
using piv = pair<int, vector<int>>;

struct query{
    int l, r, cost;
};

int N, M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i += 1){
        cin >> A[i];
    }

    cin >> M;
    vector<query> Q(M);
    for(int i = 0; i < M; i += 1){
        cin >> Q[i].l >> Q[i].r >> Q[i].cost;
        Q[i].l -= 1;
        Q[i].r -= 1;
    }

    priority_queue<piv, vector<piv>> PQ;
    map<vector<int>, int> dist;
    dist[A] = 0;
    PQ.push({dist[A], A});
    while(!PQ.empty()){
        auto [cost, cur] = PQ.top(); PQ.pop();
        cost *= -1;
        if(dist[cur] != cost) continue;
        for(auto [l, r, c] : Q){
            swap(cur[l], cur[r]);
            if(!dist.count(cur) || dist[cur] > cost + c){
                dist[cur] = cost + c;
                PQ.push({-dist[cur], cur});
            }
            swap(cur[l], cur[r]);
        }
    }

    sort(A.begin(), A.end());

    if(dist.count(A)) cout << dist[A] << '\n';
    else cout << -1 << '\n';

    return 0;
}