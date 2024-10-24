// https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/A
#include <bits/stdc++.h>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<long long> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }
    while (K--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << a[r] - a[l - 1] << '\n';
    }
}