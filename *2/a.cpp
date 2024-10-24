// https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/C
#include <bits/stdc++.h>

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<std::vector<int>> a(N + 1, std::vector<int> (M + 1, 0)), 
                                    prefixSum(N + 1, std::vector<int> (M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + a[i][j];
        }
    }
    while (K--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        int result = prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
        std::cout << result << '\n';
    }
}