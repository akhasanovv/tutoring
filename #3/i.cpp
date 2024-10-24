#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, Q;
	cin >> N >> Q;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<int> queries(Q), order(Q), ans(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> queries[i];
		order[i] = i;
	}
	sort(order.begin(), order.end(), [&] (int i, int j) {
		return queries[i] < queries[j];
	});
	// queries[order[0]] <= queries[order[1]] <= .. <= queries[order[Q - 1]]
	int j = 0;
	for (int i : order) {
		while (j < N && a[j] < queries[i]) {
			++j;
		}
		if (j < N && a[j] == queries[i]) {
			ans[i] = 1;
		}
	}
	for (int i = 0; i < Q; ++i) {
		cout << (ans[i] ? "YES" : "NO") << '\n';
	}
}