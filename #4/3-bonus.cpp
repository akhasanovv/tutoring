#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> cnt_a, cnt_b;
	// {key, value} 
	// cnt_a[i] = # количество раз, которое i встречается в a
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		++cnt_a[x];
	}
	for (int i = 0; i < m; ++i) {
		int x; cin >> x;
		++cnt_b[x];
	}
	long long ans = 0;
	for (auto [i, cnt_in_a] : cnt_a) {
		ans += 1ll * cnt_in_a * cnt_b[i];
	}
	cout << ans << '\n';
}