#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	int Q; cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int x; cin >> x;
		int L = (lower_bound(a.begin(), a.end(), x) - a.begin());
		int R = (upper_bound(a.begin(), a.end(), x) - a.begin());
		cout << R - L << '\n';
	}

	// [1, 1, 2, 3, 3, 3, 4, 5, 5, 6, 7]
	// count(5)
	// L - позиция первого вхождения числа >= x
	// R - позиция первого вхождения числа > x
	// ответ = R - L
	// позиция последнего вхождения числа >= x -> R - 1
	// [L; R - 1] находятся все x
	// (R - 1) - L + 1 = R - L

	// [1, 3, 4, 5, 7, 8]
	// count(6) = 0
	// L = 4
	// R = 4
	// R - L = 0


	// [1, 4, 2, 2]


	// онлайн запросы
	// оффлайн запросы
}