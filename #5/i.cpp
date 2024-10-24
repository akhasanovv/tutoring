#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; cin >> s;
	int N = (int)s.length();
	vector<unsigned long long> dp(N + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= N; ++i) {
		dp[i] = dp[i - 1];
		if (i >= 2 && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 33 && s[i - 2] != '0') {
			dp[i] += dp[i - 2];
		}
	}
	cout << dp[N] << '\n';
}