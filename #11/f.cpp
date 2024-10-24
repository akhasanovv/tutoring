#include <bits/stdc++.h>

using namespace std;
constexpr long long inf = 1e18 + 17;
int main() {
    int n, m; cin >> n >> m;
    vector<vector<long long>> a(n + 1, vector<long long> (m + 1, 0)), p(n + 1, vector<long long> (m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
        }
    }
    vector<long long> ans = {-inf, -inf, -inf, inf, -inf}; // сначала макс сумма, потом координаты 
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            vector<long long> arr(1, 0), prefixSum(1, 0);
            for (int k = 1; k <= m; ++k) {
                arr.push_back(p[j][k] - p[i - 1][k] - p[j][k - 1] + p[i - 1][k - 1]);
                prefixSum.push_back(prefixSum.back() + arr.back());
            }
            int mn = 0, mnIdx = 0, pr = 0;
            for (int k = 1; k < arr.size(); ++k) {
                pr += arr[k];
                if (pr - mn > ans[0] && k - mnIdx > 1) {
                    ans = {pr - mn, i, mnIdx + 1, j, k};
                }
                if (prefixSum[k - 1] < mn) {
                    mn = prefixSum[k - 1];
                    mnIdx = k;
                }
            }
            // теперь найдем подмассив с максимальной суммой
        }
    }
    cout << ans[0] << '\n';
    for (int i = 1; i < 5; ++i) cout << ans[i] << ' ';
    cout << '\n';
}