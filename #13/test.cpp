// https://codeforces.com/group/jtU6D2hVEi/contest/533277/problem/A
// #include <bits/stdc++.h>

// using namespace std;
// constexpr long long inf = 1e9 + 7;
// int main() {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     vector<long long> F(2, 1);
//     while (F.back() <= inf) {
//         F.push_back(F[F.size() - 1] + F[F.size() - 2]);
//     }
//     long long N; cin >> N;
//     for (int i = F.size() - 1; i > -1; --i) {
//         if (F[i] == N) {
//             cout << i + 1 << '\n';
//             return 0;
//         }
//     }
//     cout << -1 << '\n';
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/533277/problem/E
// #include <bits/stdc++.h>

// using namespace std;
// constexpr long long inf = 1e18 + 7;
// int main() {
//     long long n, k; cin >> n >> k;
//     vector<long long> dp(n + 1, -inf), from(n + 1, -1), coins(n + 1, 0);
//     for (int i = 2; i <= n - 1; ++i) {
//         cin >> coins[i];
//     }
//     dp[1] = 0;
//     for (int i = 2; i <= n; ++i) {
//         for (int j = i - 1; j >= i - k && j >= 1; --j) {
//             if (dp[j] + coins[i] > dp[i]) {
//                 dp[i] = dp[j] + coins[i];
//                 from[i] = j;
//             }
//         }
//     }
//     long long total = 0;
//     vector<int> jumps;
//     int current = n;
//     while (current != -1) {
//         jumps.push_back(current);
//         total += coins[current];
//         current = from[current];
//     }
//     reverse(jumps.begin(), jumps.end());
//     cout << total << '\n' << jumps.size() - 1 << '\n';
//     for (auto i : jumps) cout << i << ' ';
//     cout << '\n';
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/533277/problem/K
#include <bits/stdc++.h>

using namespace std;
constexpr long long inf = 1e18 + 7;
int main() {
    int N; cin >> N;
    vector<long long> coordinates(N + 1, 0), dp(N + 1, inf);
    for (int i = 1; i <= N; ++i) {
        cin >> coordinates[i];
    }
    sort(next(coordinates.begin()), coordinates.end());
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i - 2; j >= 0; --j) {
            dp[i] = min(dp[i], dp[j] + coordinates[i] - coordinates[j + 1]);
        }
    }
    cout << dp[N] << '\n';
}

// https://codeforces.com/group/jtU6D2hVEi/contest/533280/problem/J
// #include <bits/stdc++.h>

// using namespace std;
// int main() {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     int N, M;
//     cin >> N >> M;
//     vector<vector<bool>> dp(N + 1, vector<bool> (M + 1, 0));
//     dp[0][0] = 1;
//     for (int i = 1; i <= N; ++i) {
//         int x; cin >> x;
//         for (int j = 0; j <= M; ++j) {
//             if (dp[i - 1][j]) dp[i][j] = 1;
//             if (j >= x && dp[i - 1][j - x]) dp[i][j] = 1;
//         }
//     }
//     cout << (dp[N][M] ? "YES" : "NO") << '\n';
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/533280/problem/A
// #include <bits/stdc++.h>

// using namespace std;
// int main() {
//     int N, M;
//     cin >> N >> M;
//     vector<vector<long long>> dp(N + 1, vector<long long> (M + 1, 0));
//     dp[1][1] = 1;
//     for (int i = 1; i <= N; ++i) {
//         for (int j = 1; j <= M; ++j) {
//             dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
//         }
//     }
//     cout << dp[N][M] << '\n';
// }