#include <bits/stdc++.h>

using namespace std;
constexpr long long inf = 1e18;

int main() {
	double C; cin >> C;
	double L = -1, R = 1e6 + 1;
	for (int iters = 0; iters < 100; ++iters) {
		double M = (L + R) / 2.0;
		if (M * M + sqrt(M) <= C) {
			L = M;
		} else {
			R = M;
		}
	}
	cout << fixed << setprecision(12) << L << '\n';
}