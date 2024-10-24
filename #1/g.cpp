#include <bits/stdc++.h>

using namespace std;
constexpr int64_t inf = 1e18;

int main() {
	int n;
	cin >> n;
	vector<int64_t> a(n + 1), p(n + 1, 0);
	int64_t min_p = 0, max_comfort = -inf, cnt_max_comfort = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
		max_comfort = max(max_comfort, p[i] - min_p);
		min_p = min(min_p, p[i]);
	}
	cout << max_comfort << ' ';
	min_p = 0;
	int cnt_min_p = 1;
	for (int i = 1; i <= n; ++i) {
		if (p[i] - min_p == max_comfort) {
			cnt_max_comfort += cnt_min_p;
		}
		if (p[i] < min_p) {
			min_p = p[i];
			cnt_min_p = 1;
		} else if (p[i] == min_p) {
			++cnt_min_p;
		}
	}
	cout << cnt_max_comfort << '\n';
}