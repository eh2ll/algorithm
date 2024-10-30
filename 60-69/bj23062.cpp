#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
ll N, modA, modB, modC, a, b, c;

ll gcd(ll a, ll b) {
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll minv(ll a, ll b) {
	if (a == 0 && b == 1)
		return 0;
	if (a == 1)
		return 1;
	return b - minv(b % a, a) * b / a;
}

pll solve(pll A, pll B) {
	if (A.second == -1 || B.second == -1)
		return {-1, -1};
	if (A.second == 1)
		return B;
	if (B.second == 1)
		return A;
	ll g = gcd(A.second, B.second);
	ll l = A.second * (B.second / g);
	if ((B.first - A.first) % g != 0)
		return {-1, -1};

	ll a = A.second / g;
	ll b = B.second / g;
	ll mul = (B.first - A.first) / g;
	mul = (mul * minv(a % b, b)) % b;
	ll ret = (mul * A.second + A.first);
	ret %= l;
	while (ret <= 0)
		ret += l;
	return {ret, l};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	while (N--) {
		cin >> modA >> modB >> modC >> a >> b >> c;
		ll ret, lcm;
		tie(ret, lcm) = solve({a, modA}, {b, modB});
		if (ret == -1) {
			cout << "-1\n";
			continue;
		}
		tie(ret, lcm) = solve({c, modC}, {ret, lcm});
		if (ret == -1) {
			cout << "-1\n";
			continue;
		}
		while (1) {
			if (ret % modB == b) {
				cout << ret << '\n';
				break;
			}
			ret += lcm;
		}
	}

	return 0;
}