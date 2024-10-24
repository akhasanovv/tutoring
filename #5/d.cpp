#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9 + 17;

int main() {
	int N; cin >> N;
	vector<int> heights(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> heights[i];
	}
	vector<int> dp(N + 1, inf);
	dp[1] = 0;
	for (int i = 2; i <= N; ++i) {
		if (i == 2) {
			dp[i] = abs(heights[i] - heights[i - 1]);
		} else {
			dp[i] = min(dp[i - 2] + 3 * abs(heights[i] - heights[i - 2]), 
						dp[i - 1] + abs(heights[i] - heights[i - 1]));
		}
	}
	cout << dp[N] << '\n';
}