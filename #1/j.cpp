#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int ans = 0;
	vector<int> a(n + 2, 0), p(n + 2, 0), s(n + 2, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = 1;
		if (a[i] == a[i - 1]) {
			p[i] += p[i - 1];
		}
		if (p[i] != n) {
			ans = max(ans, p[i]);
		}
	}
	for (int i = n; i >= 1; --i) {
		s[i] = 1;
		if (a[i] == a[i + 1]) {
			s[i] += s[i + 1];
		}
		if (s[i] != n) {
			ans = max(ans, s[i]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i - 1] == a[i + 1]) {
			ans = max(ans, p[i - 1] + s[i + 1]);
		}
	}
	cout << ans << '\n';
}