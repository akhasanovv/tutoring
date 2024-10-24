// https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/G
#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<long long> a(N + 2, 0);
    while (K--) {
        int l, r;
        std::cin >> l >> r;
        a[l] += 1;
        a[r + 1] -= 1;
    }
    for (int i = 1; i <= N; ++i) {
        a[i] += a[i - 1];
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}