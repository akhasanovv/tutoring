#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 17;

int main() {
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long l = 0, r = inf;
	while (r - l > 1) {
		long long mid = (l + r) / 2;
		long long segments = 0;
		for (int i = 0; i < n; ++i) {
			segments += a[i] / mid;
		}
		if (segments >= k) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << '\n';
}