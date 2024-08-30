#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[2020], inp[4040], p[4040];

void solve(int x){
    for(int i = 0; i < x; i += 1){
        inp[i * 2] = 0;
        inp[i * 2 + 1] = arr[i];
    }
    inp[x * 2] = 0;

    x = 2 * x + 1;
    int r = -1, k = -1;
    for(int i = 0; i < x; i += 1){
        if(i <= r) p[i] = min(r - i, p[2 * k - i]);
        while(i - p[i] - 1 >= 0 && i + p[i] + 1 < x && inp[i - p[i] - 1] == inp[i + p[i] + 1]){
            p[i] += 1;
        }
        if(r < i + p[i]) r = i + p[i], k = i;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    solve(N);

    cin >> M;
    for(int i = 0; i < M; i += 1){
        int a, b; cin >> a >> b;
        a = 2 * a - 1;
        b = 2 * b - 1;
        if(p[(a + b) / 2] >= (b - a) / 2) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}