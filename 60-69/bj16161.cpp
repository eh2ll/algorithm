#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i += 1) cin >> A[i];

    int l = 0, ans = 1;
    while(l < N - 1){
        if(A[l] > A[l + 1]){
            l += 1;
            continue;
        }
        else if(A[l] == A[l + 1]){
            l += 1;
            ans = max(ans, 2);
            continue;
        }

        int len = 0;
        stack<int> st;
        st.push(A[l]);
        while(l < N - 1 && A[l] < A[l + 1]){
            st.push(A[l + 1]);
            l += 1;
        }
        if(st.top() == A[l + 1]){
            st.pop();
            l += 1;
            len += 2;
        }
        else{
            st.pop();
            len += 1;
        }
        while(!st.empty() && l < N - 1){
            if(st.top() == A[l + 1]){
                st.pop();
                l += 1;
                len += 2;
            }
            else{
                break;
            }
        }
        ans = max(ans, len);
    }

    cout << ans << "\n";

    return 0;
}