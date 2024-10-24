#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<unsigned long long>> dp(N + 1, vector<unsigned long long> (2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        // пытаемся поставить 1. это можно сделать только тогда, когда предыдущая цифра равна 0
        dp[i][1] += dp[i - 1][0];
        // пытаемся поставить 0. это можно сделать для любой предыдущей позиции (т.е. предыдущая цифра может быть равна 0/1)
        dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
    }
    cout << dp[N][0] + dp[N][1] << '\n';
}