#include <bits/stdc++.h>

using namespace std;

int N;
int inp[22][22], arr[22][22];

int chk(){
    int cnt = 0;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            if(cnt >= arr[i][j]) continue;
            cnt = arr[i][j];
        }
    }

    return cnt;
}

void move(int dir){
    if(dir == 0){  
        for(int j = 1; j <= N; j += 1){
            int hgt = N;
            for(int i = N; i > 0; i -= 1){
                if(arr[i][j] == 0) continue;
                int dmp = arr[i][j];
                arr[i][j] = 0;
                arr[hgt--][j] = dmp;
            }

            for(int i = N; i > 0; i -= 1){
                if(arr[i][j] == 0) continue;
                
                if(arr[i][j] == arr[i - 1][j]){
                    arr[i][j] *= 2;
                    arr[i - 1][j] = 0;
                }
            }

            hgt = N;
            for(int i = N; i > 0; i -= 1){
                if(arr[i][j] == 0) continue;
                int dmp = arr[i][j];
                arr[i][j] = 0;
                arr[hgt--][j] = dmp;
            }
        }
    }
    else if(dir == 1){
        for(int i = 1; i <= N; i += 1){
            int wgt = N;
            for(int j = N; j > 0; j -= 1){
                if(arr[i][j] == 0) continue;
                int dmp = arr[i][j];
                arr[i][j] = 0;
                arr[i][wgt--] = dmp;
            }

            for(int j = N; j > 0; j -= 1){
                if(arr[i][j] == 0) continue;

                if(arr[i][j] == arr[i][j - 1]){
                    arr[i][j] *= 2;
                    arr[i][j - 1] = 0;
                }
            }

            wgt = N;
            for(int j = N; j > 0; j -= 1){
                if(arr[i][j] == 0) continue;
                int dmp = arr[i][j];
                arr[i][j] = 0;
                arr[i][wgt--] = dmp;
            }
        }
    }
    else if(dir == 2){
        for(int j = 1; j <= N; j += 1){
            int hgt = 1;
            for(int i = 1; i <= N; i += 1){
                if(arr[i][j] == 0) continue;
                int dmp = arr[i][j];
                arr[i][j] = 0;
                arr[hgt++][j] = dmp;
            }

            for(int i = 1; i <= N; i += 1){
                if(arr[i][j] == 0) continue;

                if(arr[i][j] == arr[i + 1][j]){
                    arr[i][j] *= 2;
                    arr[i + 1][j] = 0;
                }

                hgt += 1;
            }

            hgt = 1;
            for(int i = 1; i <= N; i += 1){
                if(arr[i][j] == 0) continue;
                int dmp = arr[i][j];
                arr[i][j] = 0;
                arr[hgt++][j] = dmp;
            }
        }
    }
    else{
        for(int i = 1; i <= N; i += 1){
            int wgt = 1;
            for(int j = 1; j <= N; j += 1){
                if(arr[i][j] == 0) continue;
                int dmp = arr[i][j];
                arr[i][j] = 0;
                arr[i][wgt++] = dmp;
            }
            
            for(int j = 1; j <= N; j += 1){
                if(arr[i][j] == 0) continue;

                if(arr[i][j] == arr[i][j + 1]){
                    arr[i][j] *= 2;
                    arr[i][j + 1] = 0;
                }
            }

            wgt = 1;
            for(int j = 1; j <= N; j += 1){
                if(arr[i][j] == 0) continue;
                int dmp = arr[i][j];
                arr[i][j] = 0;
                arr[i][wgt++] = dmp;
            }
        }
    }
}

void sol(int iter){
    memcpy(arr, inp, sizeof(arr));    
    while(1){
        int dir = iter % 4;
        iter /= 4;
        move(dir);
        if(iter == 0) break;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i += 1){
        for(int j = 1; j <= N; j += 1){
            cin >> inp[i][j];
        }
    }

    int res = 0;
    for(int bit = 0; bit < 1024; bit += 1){
        sol(bit);

        // if(res < chk()){
        //     for(int i = 1; i <= N; i += 1){
        //         for(int j = 1; j <= N; j += 1){
        //             cout << arr[i][j] << ' ';
        //         }
        //         cout << '\n';
        //     } 
        //     cout << '\n';
        // }
        res = max(res, chk());

        // for(int i = 1; i <= N; i += 1){
        //     for(int j = 1; j <= N; j += 1){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << res << '\n';

    return 0;
}