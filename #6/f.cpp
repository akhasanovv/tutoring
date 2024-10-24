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
	vector<vector<bool>> take(N + 1, vector<bool> (M + 1, 0));
	dp[0][0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			if (dp[i - 1][j] > dp[i][j]) {
				dp[i][j] = dp[i - 1][j];
				take[i][j] = true;
			}
			take[i][j] = false;
			if (j - m[i] >= 0 && dp[i - 1][j - m[i]] + c[i] > dp[i][j]) {
				dp[i][j] =  dp[i - 1][j - m[i]] + c[i];
				take[i][j] = true;
			}
		}
	}
	int mx = 0;
	for (int i = 0; i <= M; ++i) {
		if (dp[N][i] > dp[N][mx]) {
			mx = i;
		}
	}
	for (int i = N; i >= 1; --i) {
		if (take[i][mx]) {
			cout << i << '\n';
			mx -= m[i];
		}
	}
}