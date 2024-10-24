#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> dp(N + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = i - 1; j >= max(1, i - K); --j) {
			dp[i] += dp[j];
		}
	}
	cout << dp[N] << '\n';
}