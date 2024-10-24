#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	while (q--) {
		int x; cin >> x;
		int ans = (upper_bound(a.begin(), a.end(), x) - a.begin());
		cout << ans << '\n';
	}
}

vector<int> A;
sort(A.begin(), A.end());