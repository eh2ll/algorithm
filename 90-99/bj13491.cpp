#include <bits/stdc++.h>

using namespace std;

int N, M, mx;
vector<int> A;

void dfs(int pos, vector<int> &arr, int day){
    // cout << "dfs(" << pos << ' ' << day << ") :";
    // for(int i = 0; i < arr.size(); i += 1){
    //     cout << ' ' << arr[i];
    // }
    // cout << '\n';

    int cnt = arr.size();
    if(cnt == 1 || pos & 1){
        mx = max(mx, day);
        return;
    }

    int ret = 0;
    for(int nxt = pos + 1; nxt < cnt; nxt += 1){
        vector<int> nxtarr;
        nxtarr.emplace_back(arr[pos] + arr[nxt]);
        for(int i = 0; i < cnt; i += 1){
            if(i == pos || i == nxt) continue;
            else if(i < cnt - 1){
                int j = i + 1;
                while(j < cnt && (j == pos || j == nxt)) j += 1;
                if(j < cnt) nxtarr.emplace_back(arr[i] + arr[j]);
                else nxtarr.emplace_back(arr[i]);
                i = j;
            }
            else{
                nxtarr.emplace_back(arr[i]);
            }
        }
        sort(nxtarr.begin(), nxtarr.end(), greater<int>());
        int nxtpos = -1;
        for(int i = 0; i < nxtarr.size(); i += 1){
            if(nxtarr[i] == arr[pos] + arr[nxt]){
                nxtpos = i;
                break;
            }
        }
        dfs(nxtpos, nxtarr, day + 1);
    }
    vector<int> nxtarr;
    nxtarr.emplace_back(arr[pos]);
    for(int i = 0; i < cnt; i += 1){
        if(i == pos) continue;
        else if(i < cnt - 1){
            int j = i + 1;
            while(j < cnt && j == pos) j += 1;
            if(j < cnt) nxtarr.emplace_back(arr[i] + arr[j]);
            else nxtarr.emplace_back(arr[i]);
            i = j;
        }
        else{
            nxtarr.emplace_back(arr[i]);
        } 
    }
    sort(nxtarr.begin(), nxtarr.end(), greater<int>());
    int nxtpos = -1;
    for(int i = 0; i < nxtarr.size(); i += 1){
        if(nxtarr[i] == arr[pos]){
            nxtpos = i;
            break;
        }
    }
    dfs(nxtpos, nxtarr, day + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    for(int cases = 1; cases <= tc; cases += 1){
        mx = -1;
        A.clear();

        int N, M; cin >> N >> M;
        for(int i = 0; i < N; i += 1){
            int x; cin >> x;
            A.emplace_back(x);
        }

        dfs(M - 1, A, 1);

        cout << "Data Set " << cases << ":" << '\n';
		cout << mx << '\n';
		cout << '\n';
    }

    return 0;
}