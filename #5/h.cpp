#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9 + 17;

int main() {
	int N; cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	vector<int> dp(N + 1, inf);
	dp[0] = 0;
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j < i; ++j) {
			dp[i] = min(dp[i], dp[j - 1] + x[i - 1] - x[j - 1]);
		}
	}
	cout << dp[N] << '\n';
}