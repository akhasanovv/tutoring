// https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/H
#include <bits/stdc++.h>

const int maxCoord = 1007;
int prefixSum[maxCoord][maxCoord], add[maxCoord][maxCoord];
int main() {
    int N, K;
    std::cin >> N >> K;
    while (N--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        ++x1, ++y1, ++x2, ++y2;
        --x2, --y2;
        if (x1 <= x2 && y1 <= y2) {
            add[x1][y1] += 1;
            add[x1][y2 + 1] -= 1;
            add[x2 + 1][y1] -= 1;
            add[x2 + 1][y2 + 1] += 1;
        }
    }
    for (int i = 1; i < maxCoord; ++i) {
        for (int j = 1; j < maxCoord; ++j) {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + add[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i < maxCoord; ++i) {
        for (int j = 1; j < maxCoord; ++j) {
            if (prefixSum[i][j] == K) {
                ++res;
            }
        }
    }
    std::cout << res << '\n';
}