#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> V;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    V.resize(N);
    iota(V.begin(), V.end(), 1);

    do{
        for(auto c : V) cout << c << ' ';
        cout << '\n';
    }while(next_permutation(V.begin(), V.end()));

    return 0;
}