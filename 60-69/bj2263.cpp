#include <bits/stdc++.h>

using namespace std;

int N;
int arr1[100005], arr2[100005], idx[100005];
vector<int> res;

void sol(int st1, int en1, int st2, int en2){
    if(st1 > en1 || st2 > en2) return;

    int mid = idx[arr2[en2]];
    res.push_back(arr1[mid]);

    sol(st1, mid - 1, st2, st2 + (mid - st1) - 1);
    sol(mid + 1, en1, st2 + (mid - st1), en2 - 1);

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr1[i];
        idx[arr1[i]] = i;
    }
    for(int i = 0; i < N; i += 1){
        cin >> arr2[i];
    }

    sol(0, N - 1, 0, N - 1);

    for(auto c : res) cout << c << ' ';
    cout << '\n';

    return 0;
}


//             8
//       7            9
//   5       6     10  11
// 1   2   3   4