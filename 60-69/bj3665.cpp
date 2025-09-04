#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int N; cin >> N;
        vector<int> A(N + 1), B(N + 1);
        for(int i = 1; i <= N; i += 1){
            int x; cin >> x;
            A[x] = i;
        }
        int Q; cin >> Q;
        while(Q--){
            int a, b; cin >> a >> b;
            if(A[a] > A[b]) swap(a, b);
            B[a] += 1;
            B[b] -= 1;
        }

        vector<int> ans(N + 1, -1);
        for(int i = 1; i <= N; i += 1){
            ans[A[i] + B[i]] = i;
        }
        for(int i = 1; i <= N; i += 1){
            if(ans[i] == -1) ans.clear();
        }

        if(ans.empty()){
            cout << "IMPOSSIBLE" << '\n';
        }
        else{
            for(int i = 1; i <= N; i += 1){
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}