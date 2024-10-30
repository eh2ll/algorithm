#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;
using ld = long double;
using Point = pair<ld, ld>;

int arr[10];
vector<int> tmp;

// int ccw(Point a, Point b, Point c){
//     ld res = a.X * b.Y + b.X * c.Y + c.X * a.Y;
//     res -= a.Y * b.X + b.Y * c.X + c.Y * a.X;
//     return (res > 0) - (res < 0);
// }

int ccw(Point a, Point b, Point c){
    ld res = a.X * b.Y + b.X * c.Y + c.X * a.Y;
    res -= a.Y * b.X + b.Y * c.X + c.Y * a.X;
    return (res > 0) - (res < 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 8; i += 1){
        cin >> arr[i];
        tmp.push_back(i);
    }
    sort(tmp.begin(), tmp.end());

    int res = 0;
    do{
        int flag = 1;
        for(int i = 0; i < 8; i += 1){
            Point a = {0, arr[ tmp[i] ]};
            Point b = {arr[ tmp[(i + 1) % 8] ] / sqrt(2), arr[ tmp[(i + 1) % 8] ] / sqrt(2)};
            Point c = {arr[ tmp[(i + 2) % 8] ], 0};
            // cout << tmp[i] << ' ' << tmp[(i + 1) % 8] << ' ' << tmp[(i + 2) % 8] << '\n';
            // cout << a.X << ' ' << a.Y << ", " << b.X << ' ' << b.Y << ", " << c.X << ' ' << c.Y;
            // cout << " : " << ccw(a, b, c) << '\n';
            if(ccw(a, b, c) > 0){
                flag = 0;
                break;
            }
        }
        res += flag;
    }while(next_permutation(tmp.begin(), tmp.end()));

    cout << res << '\n';

    return 0;
}