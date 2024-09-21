
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cout << "start\n";
//     cin >> N >> M >> K;
//     cout << N << " " << M << " " << K << '\n';
//     int H = int(ceil(log2(N)));
//     int S = (1 << (H + 1));
//     // arr.resize(N + 1);
//     lazy.resize(N + 1);
//     tree.resize(S);

//     cout << 0 << '\n';

//     for(int i = 0; i < N; i += 1){
//         ll x; cin >> x;
//         arr.push_back(x);
//     }

//     cout << 1 << '\n';
//     init(1, 0, N - 1);
//     cout << 2 << '\n';

//     for(int i = 0; i < M + K; i += 1){
//         int op; cin >> op;
//         if(op == 1){
//             ll b, c, d; cin >> b >> c >> d;
//             update_range(1, 0, N - 1, b - 1, c - 1, d);
//         }
//         else{
//             int b, c; cin >> b >>c;
//             cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
//         }
//     }

//     return 0;
// }