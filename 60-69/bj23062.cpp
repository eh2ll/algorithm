#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll N, modA, modB, modC, a, b, c;

tuple<ll, ll, ll> xgcd(ll a, ll b){
	if(b == 0) return {a, 1, 0};

	auto [g, x, y] = xgcd(b, a % b);

	return {g, y, x - a / b * y};
}

pair<ll, ll> crt(pll a, pll b){
	auto [g, s, t] = xgcd(a.second, b.second);
	if((b.first - a.first) % g) return {-1, -1};

	ll lcm = a.second / g * b.second;

	// ll ret = (s * (b.first - a.first) / g * a.second + a.first) % lcm; 

	__int128_t ret = (__int128_t)s * (b.first - a.first) / g;
	ret *= a.second;
	ret += a.first;
	ret %= lcm;

	if(ret < 0) ret += lcm;

	return {(ll)(ret), lcm};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	while (N--) {
		cin >> modA >> modB >> modC >> a >> b >> c;
		if(b > c){
			swap(b, c);
			swap(modB, modC);
		}
		if(a > b){
			swap(a, b);
			swap(modA, modB);
		}
		if(b > c){
			swap(b, c);
			swap(modB, modC);
		}

		ll ret, lcm;
		tie(ret, lcm) = crt({a, modA}, {b, modB});
		// cout << ret << ' ' << lcm << '\n';
		if (ret == -1) {
			cout << "-1\n";
			continue;
		}
		tie(ret, lcm) = crt({c, modC}, {ret, lcm});
		// cout << ret << ' ' << lcm << '\n';
		cout << ret << '\n';
	}

	return 0;
}

// // #include <bits/stdc++.h>

// // #define getint(n) int n; scanf("%d%*c", &n)
// // #define getll(n) long long n; scanf("%lld%*c", &n)
// // #define getchar(n) char n; scanf("%c%*c", &n);

// // #define forr(i, n) for(int i=1;i<=(n);i++)
// // #define fors(i, s, e) for(int i=(s); i<=(e); i++)
// // #define fore(i, e, s) for(int i=(e); i>=(s); i++)

// // #define fi first
// // #define se second
// // #define all(v) (v).begin(), (v).end()
// // #define rall(v) (v).rbegin(), (v).rend()
// // #define pb push_back

// // using namespace std;
// // using ll = long long; using lll = __int128_t;
// // using pii = pair<int,int>; using pll = pair<ll,ll>;
// // using vi = vector<int>; using vl = vector<ll>;
// // using vii = vector<pii>; using vll = vector<pll>;

// // const int N = 1e5+7;

// // pll diophantos(ll a, ll b)
// // {
// //     assert(a>0 and b>=0);
// //     if(b == 0) return {1, 0};
// //     auto [y, x] = diophantos(b, a%b); y = y-(a/b)*x;
// //     if(x < 0 or x >= b)
// //     {
// //         ll t = x/b;
// //         if(x%b < 0) t--;

// //         x -= b*t; y += a*t;
// //     }
// //     return {x, y};
// // }
// // pll crt(pll p, pll q)
// // {
// //     if(p.fi > q.fi) swap(p, q);
// //     auto [a, A] = p;
// //     auto [b, B] = q;

// //     ll g = gcd(A, B);
// //     if((b-a)%g != 0) return {-1, -1};
    
// //     ll i = A, j = B, k = b-a;
// //     i/=g; j/=g; k/=g;
// //     auto [x, y] = diophantos(i, j);
// //     return {(ll)((a+(lll)A*k*x)%(A*B/g)), A*B/g};
// // }
// // void solve()
// // {
// //     getll(A); getll(B); getll(C);
// //     getll(a); getll(b); getll(c);

// //     pll i = {a, A}, j = {b, B}, k = {c, C};
// //     i = crt(i, j); if(i.fi==-1) {printf("-1\n"); return;}
// //     i = crt(i, k); if(i.fi==-1) {printf("-1\n"); return;}
    
// //     printf("%lld\n", i.fi%i.se);
// // }
// // int main()
// // {
// //     getint(Q);
// //     while(Q--) solve();
// // }


// #include <bits/stdc++.h>
// #define all(v) v.begin(), v.end()
// #define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
// using namespace std;
// using ll = long long;
// using P = pair<ll,ll>;
// ll mod(ll a, ll b){ return (a %= b) >= 0 ? a : a + b; }
// tuple<ll,ll,ll> ext_gcd(ll a, ll b){
//     if(b == 0) return {a, 1, 0};
//     auto [g,x,y] = ext_gcd(b, a % b);
//     return {g, y, x - a/b * y};
// }
// pair<ll,ll> crt(ll a1, ll m1, ll a2, ll m2){
//     ll g = gcd(m1, m2), m = m1 / g * m2;
//     if((a2 - a1) % g) return {-1, -1};
//     ll md = m2/g, s = mod((a2-a1)/g, m2/g);
//     ll t = mod(get<1>(ext_gcd(m1/g%md, m2/g)), md);
//     return { a1 + s * t % md * m1, m };
// }
// // a = a_i (mod m_i)를 만족하는 {a, lcm(m_1, ... , m_k)} 반환
// // a가 존재하지 않는 경우 {-1, -1} 반환
// pair<ll,ll> crt(const vector<ll> &a, const vector<ll> &m){
//     ll ra = a[0], rm = m[0];
//     for(int i=1; i<m.size(); i++){
//         auto [aa,mm] = crt(ra, rm, a[i], m[i]);
//         if(mm == -1) return {-1, -1}; else tie(ra,rm) = tie(aa,mm);
//     }
//     return {ra, rm};
// }
// void solve(){
//     ll A, B, C, a, b, c; cin >> A >> B >> C >> a >> b >> c;
//     auto [ra, rm] = crt({a, b, c}, {A, B, C});
//     cout << ra << "\n";
// }
// int main(){
//     cin.tie(0)->sync_with_stdio(0);
//     int T; cin >> T;
//     while(T--)solve();
// }

