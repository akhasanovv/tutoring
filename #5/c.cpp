#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> dp(N + 1, 0), bad(N + 1, 0);
	for (int i = 0; i < K; ++i) {
		int x; cin >> x;
		bad[x] = 1;
	}
	dp[0] = 1;
	for (int i = 0; i <= N; ++i) {
		if (i - 1 >= 0) {
			dp[i] += dp[i - 1];
		}
		if (i - 2 >= 0) {
			dp[i] += dp[i - 2];
		}
		if (bad[i]) {
			dp[i] = 0;
		}
	}
	cout << dp[N] << '\n';
}