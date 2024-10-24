#include <bits/stdc++.h>

using namespace std;
int main() {
    int N; cin >> N;
    vector<int> a(N), dp(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int maxLen = 0;
    for (int i = 0; i < N; ++i) {
        dp[i] = 1;
        for (int j = i - 1; j > -1; --j) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    cout << maxLen << '\n';
}