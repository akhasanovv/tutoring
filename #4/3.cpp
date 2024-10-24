#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	int l = 0, r = 0;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		while (l < m && b[l] < a[i]) {
			++l;
		}
		while (r < m && b[r] <= a[i]) {
			++r;
		}
		ans += r - l;
		// то же самое, что и
		// ans += (upper_bound(b.begin(), b.end(), a[i]) - lower_bound(b.begin(), b.end(), a[i]));
	}
	cout << ans << '\n';
}