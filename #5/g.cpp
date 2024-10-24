#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9 + 17;

int main() {
	int N; cin >> N;
	vector<int> a(N + 1, inf), b(N + 1, inf), c(N + 1, inf), dp(N + 2, inf);
	for (int i = 1; i <= N; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	dp[N + 1] = 0;
	dp[N] = a[N];
	dp[N - 1] = min(b[N - 1], a[N - 1] + a[N]);
	for (int i = N - 2; i >= 1; --i) {
		dp[i] = min({dp[i + 1] + a[i], dp[i + 2] + b[i], dp[i + 3] + c[i]});
	}
	cout << dp[1] << '\n';
}