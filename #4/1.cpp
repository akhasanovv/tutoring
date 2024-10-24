#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m), ans(n + m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	int i = 0, j = 0;
	while (i < n || j < m) {
		if (j == m || (i < n && a[i] <= b[j])) {
			ans[i + j] = a[i];
			++i;
		} else {
			ans[i + j] = b[j];
			++j;
		}
	}
	for (auto x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
}