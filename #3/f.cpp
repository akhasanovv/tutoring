#include <bits/stdc++.h>

using namespace std;

double a, b, c, d;
double f(double x) {
	return a * x * x * x + b * x * x + c * x + d;
}

int main() {
	cin >> a >> b >> c >> d;
	if (a > 0) {
		// f(x) возрастает 
		double l = -1e18, r = 1e18;
		for (int iters = 0; iters < 200; ++iters) {
			double m = (l + r) / 2;
			if (f(m) <= 0) {
				l = m;
			} else {
				r = m;
			}
		}
		cout << fixed << setprecision(12) << l << '\n';
	} else {
		// f(x) убывает
		double l = -1e18, r = 1e18;
		for (int iters = 0; iters < 200; ++iters) {
			double m = (l + r) / 2;
			if (f(m) <= 0) {
				r = m;
			} else {
				l = m;
			}
		}
		cout << fixed << setprecision(12) << r << '\n';
	}
}