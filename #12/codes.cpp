// https://codeforces.com/group/jtU6D2hVEi/contest/104934/problem/F
// #include <bits/stdc++.h>

// using namespace std;
// int main() {
//     int a, b; cin >> a >> b;
//     for (int i = 1; i * i <= b; ++i) {
//         if (i * i >= a) cout << i * i << ' ';
//     }
//     cout << '\n';
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/104934/problem/G
// #include <bits/stdc++.h>

// using namespace std;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     string x; int ans = 0; cin >> x;
//     for (char c : x) ans += (c - '0');
//     cout << ans << '\n';
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/104934/problem/N
// #include <bits/stdc++.h>

// using namespace std;
// const long long inf = 1e18 + 17;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     long long mx1 = -inf, mx2 = -inf, n;
//     while (true) {
//         cin >> n;
//         if (n == 0) break;
//         if (n >= mx1) {
//             mx2 = mx1;
//             mx1 = n;
//         } else if (n > mx2) {
//             mx2 = n;
//         }
//     }
//     cout << mx2 << '\n';
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/104934/problem/R
// #include <bits/stdc++.h>

// using namespace std;
// const int inf = 1e9 + 17;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n; cin >> n;
//     int maxSum = -inf, L = 0, minPrefix = 0, curPrefix = 0, ansL = -1, ansR = -1;
//     for (int R = 1; R <= n; ++R) {
//         int x; cin >> x;
//         curPrefix += x;
//         if (curPrefix - minPrefix > maxSum) {
//             maxSum = curPrefix - minPrefix;
//             ansL = L + 1;
//             ansR = R;
//         }
//         if (curPrefix < minPrefix) {
//             minPrefix = curPrefix;
//             L = R;
//         }
//     }
//     cout << ansL << ' ' << ansR << ' ' << maxSum << '\n';
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/B
// #include <bits/stdc++.h>

// using namespace std;
// const int inf = 1e9 + 17;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int N; cin >> N;
//     vector<int> a(N + 1);
//     for (int i = 1; i <= N; ++i) {
//         cin >> a[i];
//         if (a[i] == 0) a[i] = 1;
//         else a[i] = 0;
//         a[i] += a[i - 1];
//     }
//     int K; cin >> K;
//     while (K--) {
//         int l, r; cin >> l >> r;
//         cout << a[r] - a[l - 1] << ' ';
//     }
//     cout << '\n';
// }



// https://codeforces.com/group/jtU6D2hVEi/contest/104997/problem/E
// #include <bits/stdc++.h>

// using namespace std;
// const int inf = 1e9 + 17;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int N, x; cin >> N;
//     vector<int> cnt(N + 1, 0);
//     while (cin >> x) {
//         ++cnt[x];
//     }
//     for (int i = 1; i <= N; ++i) cout << cnt[i] << ' ';
//     cout << '\n';
// }




// https://codeforces.com/group/jtU6D2hVEi/contest/105000/problem/A
// #include <bits/stdc++.h>

// using namespace std;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int N; cin >> N;
//     vector<int> a(N + 1);
//     for (int i = 1; i <= N; ++i) {
//         cin >> a[i];
//     }
//     for (int i = 2; i <= N; ++i) {
//         if (a[i - 1] >= a[i]) {
//             cout << "No\n";
//             return 0;
//         }
//     }
//     cout << "Yes\n";
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/533121/problem/I
// #include <bits/stdc++.h>

// using namespace std;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
    
//     int N, K;
//     cin >> N >> K;
//     vector<int> a(N);
//     for (int i = 0; i < N; ++i) cin >> a[i];
//     int l = 0, r = 1e9 + 17;
//     while (r - l > 1) {
//         int mid = (l + r) / 2;
//         int cntCows = 0, prev;
//         for (int i = 0; i < N; ++i) {
//             if (i == 0 || a[i] - prev >= mid) {
//                 prev = a[i];
//                 ++cntCows;
//             }
//         }
//         if (cntCows >= K) {
//             l = mid;
//         } else {
//             r = mid;
//         }
//     }
//     cout << l << '\n';
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/533121/problem/L
// #include <bits/stdc++.h>

// using namespace std;
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n; cin >> n;
//     vector<int> l(n), x(n);
//     for (int i = 0; i < n; ++i) cin >> l[i];
//     for (int i = 0; i < n; ++i) cin >> x[i];
//     int t; cin >> t;
//     double L = 0, R = 1e12;
//     for (int _ = 0; _ < 100; ++_) {
//         double M = (L + R) / 2.0;
//         double totalTime = 0, curSpeed = M;
//         for (int i = 0; i < n; ++i) {
//             totalTime += (double)l[i] / curSpeed;
//             curSpeed += x[i];
//         }
//         if (totalTime <= t) {
//             R = M;
//         } else {
//             L = M;
//         }
//     }
//     cout << fixed << setprecision(10) << R << '\n';
// }


// https://codeforces.com/group/jtU6D2hVEi/contest/533277/problem/H
// #include <bits/stdc++.h>

// using namespace std;
// const int inf = 1e9 + 17;
// int main() {
//     int N, ans = 0; cin >> N;
//     vector<int> dp(N + 1, inf);
//     dp[0] = -inf;
//     for (int i = 0; i < N; ++i) {
//         int x; cin >> x;
//         for (int j = 0; j < N; ++j) {
//             if (x > dp[j] && x < dp[j + 1]) {
//                 dp[j + 1] = x;
//                 ans = max(ans, j + 1);
//                 break;
//             }
//         }
//     }
//     cout << ans << '\n';
// }

// https://codeforces.com/group/jtU6D2hVEi/contest/533277/problem/I
#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 17;
int main() {
    freopen("input.txt", "r", stdin); // считывать данные ИЗ файла input.txt
    freopen("output.txt", "w", stdout); // выводить данные В файл output.txt
    int N; cin >> N;
    vector<int> dp(N + 1, inf), par(N + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        if (dp[i - 1] + 1 <= dp[i]) {
            dp[i] = dp[i - 1] + 1;
            par[i] = 1;
        }
        if (i >= 5 && dp[i - 5] + 1 <= dp[i]) {
            dp[i] = dp[i - 5] + 1;
            par[i] = 5;
        }
        if (i >= 6 && dp[i - 6] + 1 <= dp[i]) {
            dp[i] = dp[i - 6] + 1;
            par[i] = 6;
        }
    }
    vector<int> ans;
    while (N > 0) {
        ans.push_back(par[N]);
        N -= par[N];
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}





