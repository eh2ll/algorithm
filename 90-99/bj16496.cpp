#include <bits/stdc++.h>

using namespace std;

int N;
string arr[1003];

bool comp(const string& a, const string& b){
    string ab = a + b, ba = b + a;
    return ab > ba;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i += 1){
        cin >> arr[i];
    }

    sort(arr, arr + N, comp);

    if(arr[0] == "0" && arr[N - 1] == "0"){
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 0; i < N; i += 1){
        cout << arr[i];
    }
    cout << '\n';

    return 0;
}