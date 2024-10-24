#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, W; cin >> N >> W;
	vector<int> w(N);
	for (int i = 0; i < N; ++i) {
		cin >> w[i];
	}
	vector<int> A(W + 1, 0);
	A[0] = 1;
	for (int i = 0; i < N; ++i) {
		vector<int> B = A;
		for (int weight = 0; weight <= W; ++weight) {
			if (weight + w[i] <= W && A[weight] == 1) {
				B[weight + w[i]] = 1;
			}
		}
		A = B;
	}
	if (A[W] == 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}