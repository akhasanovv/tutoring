#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9 + 17;

int main() {
	int N; cin >> N;
	vector<int> dp(N + 1, inf);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		dp[i] = min(dp[i - 1], dp[i - 2]) + (i % 10);
	}
	cout << dp[N] << '\n';
}