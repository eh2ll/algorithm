#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr1, arr2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        int x; cin >> x;
        arr1.push_back(x);
    }
    cin >> M;
    for(int i = 1; i <= M; i += 1){
        int x; cin >> x;
        arr2.push_back(x);
    }

    vector<int> res;
    auto it = arr1.begin();
    auto ta = arr2.begin();
    while(arr1.size() > 0 && it != arr1.end() && ta != arr2.end()){
        // for(auto c : arr1) cout << c << ' ';
        // cout << '\n';
        // for(auto c : arr2) cout << c << ' ';
        // cout << '\n';

        auto mx1 = max_element(it, arr1.end());
        auto mx2 = max_element(ta, arr2.end());
        if(*mx1 == *mx2){
            res.push_back(*mx1);
            arr1.erase(mx1);
            arr2.erase(mx2);
            it = mx1;
            ta = mx2;
        }
        else if(*mx1 > *mx2){
            arr1.erase(mx1);
        }
        else{
            arr2.erase(mx2);
        }
    }

    cout << res.size() << '\n';
    for(auto c : res) cout << c << ' ';
    cout << '\n';

    return 0;
}