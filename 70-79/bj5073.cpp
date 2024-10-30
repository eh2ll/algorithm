#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[3];
    while(1){
        cin >> a[0] >> a[1] >> a[2];
        if(a[0] + a[1] + a[2] == 0) break;
        sort(a, a + 3);
        if(a[0] == a[2]) cout << "Equilateral\n";
        else if(a[2] < a[0] + a[1] && (a[0] == a[1] || a[1] == a[2])) cout << "Isosceles\n";
        else if(a[2] < a[0] + a[1]) cout << "Scalene\n";
        else cout << "Invalid\n";
    }

    return 0;
}