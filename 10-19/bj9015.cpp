#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
using pii = pair<int, int>;

int dis(pii &a, pii &b){
    return (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        int N; cin >> N;
        vector<pii> A(N);
        set<pii> st;
        for(int i = 0; i < N; i += 1){
            cin >> A[i].X >> A[i].Y;
            st.insert(A[i]);
        }

        int ans = 0;
        for(int i = 0; i < N; i += 1){
            for(int j = i + 1; j < N; j += 1){
                pii a = A[i], b = A[j];
                if(a > b) swap(a, b);
                int D = dis(a, b);
                if(D <= ans) continue;
                if(a.Y > b.Y){
                    int nx1 = a.X + (a.Y - b.Y);
                    int ny1 = a.Y + (b.X - a.X);
                    int nx2 = b.X + (a.Y - b.Y);
                    int ny2 = b.Y + (b.X - a.X);
                    if(st.count({nx1, ny1}) && st.count({nx2, ny2})){
                        ans = max(ans, D);
                    }
                }
                else{
                    int nx1 = a.X + (b.Y - a.Y);
                    int ny1 = a.Y - (b.X - a.X);
                    int nx2 = b.X + (b.Y - a.Y);
                    int ny2 = b.Y - (a.X - b.X);
                    if(st.count({nx1, ny1}) && st.count({nx2, ny2})){
                        ans = max(ans, D);
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}