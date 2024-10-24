#include <bits/stdc++.h>

using namespace std;
const int M = 10000 + 17;

int main() {
	int N, S = 0;
	cin >> N;
	vector<vector<bool>> dp(N + 1, vector<bool> (M + 1, false));
	dp[0][0] = true; // можем набрать вес 0 всегда
	for (int i = 1; i <= N; ++i) {
		int x; cin >> x;
		S += x;
		for (int j = 0; j <= M; ++j) {
			if (dp[i - 1][j]) {
				// если уже на предыдущей итерации могли набрать вес j, то и на этой можем
				dp[i][j] = true;
			}
			if (j - x >= 0 && dp[i - 1][j - x]) {
				// если на предудыщей итерации могли набрать j - x, то возьмем x. 
				// таким образом, мы можем набрать j = (j - x) + x
				dp[i][j] = true;
			}
		}
	}
	if (S % 2 == 0 && dp[N][S / 2]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}