#include <bits/stdc++.h>

using namespace std;

// lower_bound(x) -> первое число >= x
// upper_bound(x) -> первое число > x

double f(double x) {
	return x * x + sqrt(x);
}

long double f(long double x) {
	return x * x + sqrtl(x);
}

int main() {
	long double C; cin >> C;
	long double l = 0, r = 1e5;

	for (int iters = 0; iters < 100; ++iters) { // 2^200
		long double m = (l + r) / 2.0;
		if (f(m) <= C) {
			l = m;
		} else {
			r = m;
		}
	}

	// 1e5

	// f(l) <= C
	cout << fixed << setprecision(12) << l << '\n';
}