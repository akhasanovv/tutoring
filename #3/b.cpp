#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, Q; cin >> N >> Q;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < Q; ++i) {
		int X; cin >> X;
		int L = (lower_bound(a.begin(), a.end(), X) - a.begin()); // индекс первого числа, >= X
		int R = (upper_bound(a.begin(), a.end(), X) - a.begin()); // индекс первого числа, > X
		if (a[L] == X) { // X есть в массиве
			cout << L + 1 << ' ' << (R - 1) + 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
}