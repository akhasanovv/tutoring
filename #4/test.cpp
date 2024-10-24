#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < k; ++i) {
		int query, l = -1, r = n;
		cin >> query;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (a[mid] >= query) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout << r + 1 << '\n';
	}
}