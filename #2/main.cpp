#include <bits/stdc++.h>

using namespace std;

vector<int> bubbleSort(vector<int> a) { // O(n ^ 2)
	int n = (int)a.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) { // a[i] <= a[j]
				// i < j
				swap(a[i], a[j]);
			}
		}
	}
	return a; // O(n^2)
}

void print(vector<int> a) {
	for (auto x : a) {
		cout << x << ' ';
	}
	cout << '\n';
}

vector<int> mergeSort(vector<int> a) { // O(n log n)
	// len(a) = 1
	if ((int)a.size() == 1) {
		return a;
	}
	// L = [0, 1, 2, .., len(a) / 2 - 1],
	// R = [len(a) / 2, len(a) / 2 + 1, ..., len(a) - 1]
	int m = (int)a.size() / 2;
	vector<int> L, R;
	for (int i = 0; i <= m - 1; ++i) {
		L.push_back(a[i]);
	}
	for (int i = m; i < (int)a.size(); ++i) {
		R.push_back(a[i]);
	}
	L = mergeSort(L);
	R = mergeSort(R);
	// L[0] <= L[1] <= .. <= L[len(L) - 1]
	// R[0] <= R[1] <= .. <= R[len(R) - 1]
	vector<int> A;
	// A = L + R
	int l = 0, r = 0;
	while (l < (int)L.size() || r < (int)R.size()) {
		// когда берем L[l]?
		// сейчас сравниваем L[l] и R[r]
		if (r == (int)R.size() || (l < (int)L.size() && L[l] <= R[r])) {
			A.push_back(L[l]);
			++l;
		} else {
			A.push_back(R[r]);
			++r;
		}
	}
	return A;
}

// [1, N] -> N - 1 + 1 = N
// N операций суммарно
// [1, N / 2] -> N / 2 - 1 + 1 = N / 2, [N / 2 + 1, N] = N - N / 2 - 1 + 1 = N / 2 -> N
// [1, N / 4] = N / 4, [N / 4 + 1, N / 2] = N / 4, N / 4, N / 4 -> N
// / 8
// / 16

// log_2(N) = k, 2^k = N

mt19937 rnd(228);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> a;
	for (int i = 0; i < 100000; ++i) {
		a.push_back(rnd());
	}
	print(mergeSort(a));
	// print(bubbleSort(a));
}










