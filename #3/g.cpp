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
		int X; cin >> X;
		int L = (lower_bound(a.begin(), a.end(), X) - a.begin()); // индекс первого числа, >= X
		int R = (upper_bound(a.begin(), a.end(), X) - a.begin()); // индекс первого числа, > X
		cout << R - L << '\n';
	}
}