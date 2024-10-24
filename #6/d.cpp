#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> dp(N + 1, vector<int> (M + 1, inf));
	dp[0][0] = 0;
	for (int i = 1; i <= N; ++i) {
		int x; cin >> x;
		for (int j = 0; j <= M; ++j) {
			if (dp[i - 1][j] != inf) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			if (j - x >= 0 && dp[i - 1][j - x] != inf) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - x] + 1);
			}
		}
	}
	if (dp[N][M] == inf) {
		cout << 0 << '\n'; // не можем набрать вес M
	} else {
		cout << dp[N][M] << '\n';
	}
}