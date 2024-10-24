#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9 + 17;
int main() {
    int N; cin >> N;
    vector<int> a(N), dp(N + 1, inf);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    dp[0] = -inf;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int l = -1, r = N + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[i] < dp[mid]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (dp[r - 1] < a[i] && a[i] < dp[r]) {
            ans = max(ans, r);
            dp[r] = a[i];
        }
    }
    cout << ans << '\n';
}