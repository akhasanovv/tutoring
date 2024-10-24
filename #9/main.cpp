#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> res;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            int alpha = 0;
            while (n % d == 0) {
                ++alpha;
                n /= d;
            }
            res.push_back({d, alpha}); // n делится на d^alpha
            // n не делится на d^(alpha+1)
        }
    }
    if (n > 1) {
        // n простое
        res.push_back({n, 1});
    }
    return res;
}

int main() {
    int x;
    cin >> x;
    vector<pair<int, int>> divs = factorize(x);
    int ans = 1;
    for (auto [p, alpha] : divs) {
        ans *= (alpha + 1);
    }
    cout << ans << '\n';
}