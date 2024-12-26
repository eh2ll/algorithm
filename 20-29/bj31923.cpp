#include <bits/stdc++.h>

using namespace std;

int N, P, Q;
int A[102], B[102], res[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> Q;
    int comp = P - Q;

    for(int i = 0; i < N; i += 1){
        cin >> A[i];
    }
    for(int i = 0; i < N; i += 1){
        cin >> B[i];
    }

    int flag = 1;
    if(comp != 0){
        for(int i = 0; i < N; i += 1){
            if((((A[i] - B[i]) % comp) == 0) && (((A[i] - B[i]) / comp) <= 0)) res[i] = -1 * (A[i] - B[i]) / comp;
            else{
                flag = 0;
                res[i] = 0x3f3f3f3f;
            }
        }
    }
    else{
        for(int i = 0; i < N; i += 1){
            if(A[i] == B[i]) continue;
            else{
                flag = 0;
                res[i] = 0x3f3f3f3f;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i += 1) if(res[i] != 0x3f3f3f3f) cnt += res[i];

    if(flag && cnt <= 10000){
        cout << "YES\n";
        for(int i = 0; i < N; i += 1) cout << res[i] << ' ';
        cout << '\n';
    }
    else cout << "NO\n";

    return 0;
}