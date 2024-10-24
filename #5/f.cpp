#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9 + 17;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<long long>> a(N + 1, vector<long long> (M + 1)), dp(N + 1, vector<long long> (M + 1, inf));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> a[i][j];
		}
	}
	dp[1][1] = a[1][1];
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (i != 1 || j != 1) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
			}
		}
	}
	cout << dp[N][M] << '\n';
}