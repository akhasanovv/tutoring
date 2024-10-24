#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; long long s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = 0, ans = 0;
	long long currentSum = 0;
	for (int r = 0; r < n; ++r) {
		currentSum += a[r];
		while (currentSum > s) {
			currentSum -= a[l];
			++l;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
}