#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int> (m + 1, 0)), dp(n + 1, vector<int> (m + 1, -inf));
	vector<vector<char>> parent(n + 1, vector<char> (m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	dp[1][1] = a[1][1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i != 1 || j != 1) {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					parent[i][j] = 'D';
					dp[i][j] = dp[i - 1][j] + a[i][j];
				} else {
					parent[i][j] = 'R';
					dp[i][j] = dp[i][j - 1] + a[i][j];
				}
			}
		}
	}
	cout << dp[n][m] << '\n';
	stack<char> ans;
	while (n > 1 || m > 1) {
		ans.push(parent[n][m]);
		if (parent[n][m] == 'D') {
			--n;
		} else {
			--m;
		}
	}
	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << '\n';
}