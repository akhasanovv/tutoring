#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<long long>> dp(N + 1, vector<long long> (3, 0));
    dp[1][1] = 1;
    dp[1][0] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i][0] += dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] += dp[i - 1][0];
        dp[i][2] += dp[i - 1][1];
    }
    cout << dp[N][0] + dp[N][1] + dp[N][2] << '\n';
}