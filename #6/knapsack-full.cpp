#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 17;

int main() {
	int N, R;
	cin >> N >> R;
	vector<int> price(N + 1), joy(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> price[i];
	}
	for (int i = 1; i <= N; ++i) {
		cin >> joy[i];
	}
	vector<vector<int>> dp(N + 1, vector<int> (R + 1, -inf));
	vector<vector<int>> take(N + 1, vector<int> (R + 1, 0));
	// take[i][j] = 0 / 1
	// нужно ли брать i элемент, если я хочу получить максимальный joy при суммарном прайсе в j
	dp[0][0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int r = 0; r <= R; ++r) {
			dp[i][r] = max(dp[i][r], dp[i - 1][r]);
			if (r + price[i] <= R) {
				dp[i][r + price[i]] = max(dp[i][r + price[i]], dp[i - 1][r] + joy[i]);
			}
		}
	}
	int ans = 0;
	for (int r = 0; r <= R; ++r) {
		ans = max(ans, dp[N][r]);
	}
	// dp[N][r <= R], 
	// take[N][r] = 1, то мы берем элемент N и идем дальше, теперь наш суммарный прайс равен r - price[N]
	// take[N][r] = 0, не берем элемент N и идем к N - 1 элементу, с суммарным прайсом также в r рублей
	cout << ans << '\n';
}