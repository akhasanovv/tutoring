#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9;

int main() {
	int N, S;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
	}
	cin >> S;
	vector<int> dp(S + 1, inf), parent(S + 1, -1);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = x[i]; j <= S; ++j) {
			if (dp[j - x[i]] + 1 < dp[j]) {
				dp[j] = dp[j - x[i]] + 1;
				parent[j] = x[i];
			}
		}
	}
	if (dp[S] == inf) {
		cout << "No solution\n";
		return 0;
	}
	while (S > 0) {
		cout << parent[S] << ' ';
		S -= parent[S];
	}
	cout << '\n';
}