#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;

int main() {
    int N; cin >> N;
    vector<int> cost(N + 1), dp(N + 1, inf);
    for (int i = 1; i <= N; ++i) {
        cin >> cost[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        if (i >= 1) {
            dp[i] = min(dp[i], dp[i - 1] + cost[i]);
        }
        if (i >= 1) {
            dp[i] = min(dp[i], dp[i - 2] + cost[i]);
        }
    }
    cout << dp[N] << '\n';
}