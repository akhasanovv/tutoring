#include <bits/stdc++.h>

using namespace std;
constexpr long long inf = 1e18;

int main() {
	int N, K;
	cin >> N >> K;

	vector<long long> a(N); // по условию a отсортирован
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < K; ++i) {
		long long Q; cin >> Q;
		// найти число в массиве a, такое что |Q - a[i]| -> минимально возможно
		// заметим, что нам достаточно рассмотреть не более 2 чисел
		// минимальное a[i] >= Q
		// и максимальное a[i] < Q
		int l = -1, r = N;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (a[m] >= Q) {
				r = m;
			} else {
				l = m;
			}
		}
		// если r < N, то a[r] -> минимальное число, >= Q
		long long minDifference = inf, ans = -1;
		if (r < N && a[r] - Q < minDifference) {
			minDifference = a[r] - Q;
			ans = a[r];
		}
		// если l > -1, то a[l] -> максимальное число, < Q
		if (l > -1 && Q - a[l] <= minDifference) {
			minDifference = Q - a[l];
			ans = a[l];
		}
		cout << ans << '\n';
	}
}