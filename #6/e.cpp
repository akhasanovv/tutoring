#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 17;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> m(N + 1), c(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> m[i];
	}
	for (int i = 1; i <= N; ++i) {
		cin >> c[i];
	}
	vector<vector<int>> dp(N + 1, vector<int> (M + 1, -inf));
	dp[0][0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j - m[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - m[i]] + c[i]);
			}
		}
	}
	cout << *max_element(dp[N].begin(), dp[N].end()) << '\n';
}