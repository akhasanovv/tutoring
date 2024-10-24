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
	int j = -1;
	for (int i = 0; i < m; ++i) {
		while (j + 1 < n && a[j + 1] < b[i]) {
			++j;
		}
		cout << j + 1 << ' ';
	}
	cout << '\n';
}