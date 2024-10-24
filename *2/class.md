### Второе занятие. Префиксные суммы

#### Задача 1
[Ссылка](https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/C)

**Код решения:**

```c++
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
```


#### Задача 2
[Ссылка](https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/A)

**Код решения:**

```c++
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
```

#### Задача 3
[Ссылка](https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/G)

**Код решения:**

```c++
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
```

#### Задача 4
[Ссылка](https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/H)

**Код решения:**

```c++
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
```