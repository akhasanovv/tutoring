#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    int64_t ans = 0;
    int pointer = -1;
    for (int i = 0; i < n; ++i) {
        while (d[i] - d[pointer + 1] > r) {
            ++pointer;
        }
        ans += pointer + 1;
    }
    cout << ans << '\n';
}