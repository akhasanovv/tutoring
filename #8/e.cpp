#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;

int main() {
    int N; cin >> N;
    vector<int> dp(N + 1, inf);
    dp[0] = 0; // изначально сумма кубов равна 0, чтобы ее получить нужно сложить 0 чисел
    for (int i = 1; i <= 101; ++i) {
        int i3 = i * i * i;
        for (int prevCnt = 0; prevCnt + i3 <= N; ++prevCnt) {
            dp[prevCnt + i3] = min(dp[prevCnt + i3], dp[prevCnt] + 1);
        }
    }
    cout << dp[N] << '\n';
}