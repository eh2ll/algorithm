#include <bits/stdc++.h>

using namespace std;

int TC;
string arr[10004];

// 초기화 다시
void bfs(int x, int y){
    fill(arr, arr + 10004, "-1");
    arr[x] = "";
    // memset(arr, 0, sizeof(arr));

    queue<int> Q;
    Q.push(x);

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int tmp = 0;
        if(cur == y) return;

        tmp = 2 * cur % 10000;
        if(arr[tmp] == "-1"){
            Q.push(tmp);
            arr[tmp] = arr[cur] + "D";
        }
        // cout << cur << ' ' << tmp << ' ' << arr[tmp] << '\n';

        tmp = (cur - 1 + 10000) % 10000;
        if(arr[tmp] == "-1"){
            Q.push(tmp);
            arr[tmp] = arr[cur] + "S";
        }
        // cout << cur << ' ' << tmp << ' ' << arr[tmp] << '\n';

        tmp = ( cur * 10 + (cur / 1000) ) % 10000;
        if(arr[tmp] == "-1"){
            Q.push(tmp);
            arr[tmp] = arr[cur] + "L";
        }
        // cout << cur << ' ' << tmp << ' ' << arr[tmp] << '\n';

        tmp = ( cur / 10 + (cur * 1000) ) % 10000;
        if(arr[tmp] == "-1"){
            Q.push(tmp);
            arr[tmp] = arr[cur] + "R";
        }
        // cout << cur << ' ' << tmp << ' ' << arr[tmp] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> TC;
    while(TC--){
        int a, b; cin >> a >> b;
        bfs(a, b);
        cout << arr[b] << '\n';
    }

    return 0;
}